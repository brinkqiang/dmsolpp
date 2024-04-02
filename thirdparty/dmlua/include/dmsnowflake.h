
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMSNOWFLAKE_H_INCLUDE__
#define __DMSNOWFLAKE_H_INCLUDE__

#include <cstdint>
#include <mutex>
#include <memory>

class CDMIDGeneratorImpl;
class CDMIDGenerator
{
public:
	inline CDMIDGenerator(int region_id = 0, int worker_id = 0);//region_id in (0-15) , worker_id in (0-1023)
	inline ~CDMIDGenerator();

	inline void Init(int region_id = 0, int worker_id = 0);
	inline uint64_t GetNextID();

private:
	std::unique_ptr<CDMIDGeneratorImpl> m_oImpl;
};

#include <chrono>
#include <cassert>

#define SNOWFLAKE_EPOCH 1388534400000

#define SNOWFLAKE_TIME_BITS 41
#define SNOWFLAKE_REGIONID_BITS 4
#define SNOWFLAKE_WORKERID_BITS 10
#define SNOWFLAKE_SEQUENCE_BITS 8

typedef struct {
    uint64_t time;
    uint64_t seq_max;
    uint64_t worker_id;
    uint64_t region_id;
    uint64_t seq;
    uint64_t time_shift_bits;
    uint64_t region_shift_bits;
    uint64_t worker_shift_bits;
} snowflake_state;

typedef struct _app_stats {
    time_t started_at;
    char* version;
    uint64_t ids;
    uint64_t waits;
    uint64_t seq_max;
    int region_id;
    int worker_id;
    uint64_t seq_cap;
} app_stats;

static inline uint64_t DMGetTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - SNOWFLAKE_EPOCH;
}

class CDMIDGeneratorImpl
{
public:
    inline CDMIDGeneratorImpl(int region_id, int worker_id) { 
        std::lock_guard<std::mutex> guard(m_oLock);
        snowflake_init(region_id, worker_id);
    }

    inline ~CDMIDGeneratorImpl() {}

    inline uint64_t GetNextID() {
        std::lock_guard<std::mutex> guard(m_oLock);
        return snowflake_id();
    }

private:
    inline uint64_t snowflake_id() {
        uint64_t millisecs = DMGetTime();
        uint64_t id = 0;

        // Catch NTP clock adjustment that rolls time backwards and sequence number overflow
        if ((m_oSnowflakeGlobalState.seq > m_oSnowflakeGlobalState.seq_max) || m_oSnowflakeGlobalState.time > millisecs) {
            ++m_oAppStats.waits;
            while (m_oSnowflakeGlobalState.time >= millisecs) {
                millisecs = DMGetTime();
            }
        }

        if (m_oSnowflakeGlobalState.time < millisecs) {
            m_oSnowflakeGlobalState.time = millisecs;
            m_oSnowflakeGlobalState.seq = 0L;
        }


        id = (millisecs << m_oSnowflakeGlobalState.time_shift_bits)
            | (m_oSnowflakeGlobalState.region_id << m_oSnowflakeGlobalState.region_shift_bits)
            | (m_oSnowflakeGlobalState.worker_id << m_oSnowflakeGlobalState.worker_shift_bits)
            | (m_oSnowflakeGlobalState.seq++);

        if (m_oAppStats.seq_max < m_oSnowflakeGlobalState.seq)
            m_oAppStats.seq_max = m_oSnowflakeGlobalState.seq;

        ++m_oAppStats.ids;
        return id;
    }

    inline int snowflake_init(int region_id, int worker_id) {
        const int max_region_id = (1 << SNOWFLAKE_REGIONID_BITS) - 1;
        if (region_id < 0 || region_id > max_region_id) {
            printf("Region ID must be in the range : 0-%d\n", max_region_id);
            assert(0);
            return -1;
        }
        const int max_worker_id = (1 << SNOWFLAKE_WORKERID_BITS) - 1;
        if (worker_id < 0 || worker_id > max_worker_id) {
            printf("Worker ID must be in the range: 0-%d\n", max_worker_id);
            assert(0);
            return -1;
        }

        m_oSnowflakeGlobalState.time_shift_bits = SNOWFLAKE_REGIONID_BITS + SNOWFLAKE_WORKERID_BITS + SNOWFLAKE_SEQUENCE_BITS;
        m_oSnowflakeGlobalState.region_shift_bits = SNOWFLAKE_WORKERID_BITS + SNOWFLAKE_SEQUENCE_BITS;
        m_oSnowflakeGlobalState.worker_shift_bits = SNOWFLAKE_SEQUENCE_BITS;

        m_oSnowflakeGlobalState.worker_id = worker_id;
        m_oSnowflakeGlobalState.region_id = region_id;
        m_oSnowflakeGlobalState.seq_max = (1L << SNOWFLAKE_SEQUENCE_BITS) - 1;
        m_oSnowflakeGlobalState.seq = 0L;
        m_oSnowflakeGlobalState.time = 0L;

        m_oAppStats.seq_cap = m_oSnowflakeGlobalState.seq_max;
        m_oAppStats.waits = 0L;
        m_oAppStats.seq_max = 0L;
        m_oAppStats.ids = 0L;
        m_oAppStats.region_id = region_id;
        m_oAppStats.worker_id = worker_id;
        return 1;
    }
private:
    snowflake_state m_oSnowflakeGlobalState;
    app_stats       m_oAppStats;
    std::mutex      m_oLock;
};


inline CDMIDGenerator::CDMIDGenerator(int region_id, int worker_id)
    : m_oImpl(new CDMIDGeneratorImpl(region_id, worker_id))
{

}

inline CDMIDGenerator::~CDMIDGenerator()
{
}

inline void CDMIDGenerator::Init(int region_id, int worker_id) 
{
	m_oImpl.reset(new CDMIDGeneratorImpl(region_id, worker_id));
}

inline uint64_t CDMIDGenerator::GetNextID()
{
    return m_oImpl->GetNextID();
}

#endif // __DMSNOWFLAKE_H_INCLUDE__