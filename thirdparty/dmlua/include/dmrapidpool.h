
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

#ifndef __DMRAPIDPOOL_H_INCLUDE__
#define __DMRAPIDPOOL_H_INCLUDE__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <stdint.h>

#include <cstring>
#include <cassert>
#include <new>

#include <set>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <memory>

class IDMRapidInfo
{
public:
    virtual ~IDMRapidInfo() {}
    virtual uint64_t GetFreeCount(void) = 0;
    virtual uint64_t GetMallocCount(void) = 0;
    virtual const char* GetObjName(void) = 0;
    virtual uint64_t GetObjSize(void) = 0;
};

class CDMRapidFactory
{
    typedef std::set<IDMRapidInfo*>   SetDMRapidInfo;
    typedef SetDMRapidInfo::iterator  SetDMRapidInfoIt;

    typedef std::map<std::string, SetDMRapidInfo> MapDMRapidInfo;
    typedef MapDMRapidInfo::iterator              MapDMRapidInfoIt;
public:
    static CDMRapidFactory* Instance() {
        static CDMRapidFactory s_oT;
        return &s_oT;
    }

    void RegPool(IDMRapidInfo* poInfo)
    {
        std::lock_guard guard(m_lock);

        MapDMRapidInfoIt mapIt = m_mapDMRapidInfo.find(poInfo->GetObjName());
        if (mapIt != m_mapDMRapidInfo.end())
        {
            SetDMRapidInfo& set = mapIt->second;

            SetDMRapidInfoIt setIt = set.find(poInfo);
            if (setIt != set.end())
            {
                assert(0);
                return;
            }
        }

        m_mapDMRapidInfo[poInfo->GetObjName()].insert(poInfo);
    }

    void UnRegPool(IDMRapidInfo* poInfo)
    {
        std::lock_guard guard(m_lock);

        MapDMRapidInfoIt mapIt = m_mapDMRapidInfo.find(poInfo->GetObjName());
        if (mapIt == m_mapDMRapidInfo.end())
        {
            assert(0);
            return;
        }

        SetDMRapidInfo& set = mapIt->second;

        SetDMRapidInfoIt setIt = set.find(poInfo);
        if (setIt == set.end())
        {
            assert(0);
            return;
        }

        set.erase(setIt);
        if (set.empty())
        {
            m_mapDMRapidInfo.erase(mapIt);
        }
    }

    std::string Print()
    {
        std::lock_guard guard(m_lock);

        std::stringstream ss;
        ss << "ObjName, " << "ObjSize, " << "MallocCount, " << "FreeCount, " << "TotalSize" << std::endl;

        for (MapDMRapidInfoIt It = m_mapDMRapidInfo.begin(); It != m_mapDMRapidInfo.end(); ++It)
        {
            SetDMRapidInfo& set = It->second;
            for (SetDMRapidInfoIt It2 = set.begin(); It2 != set.end(); ++It2)
            {
                ss << (*It2)->GetObjName() << ", " << (*It2)->GetObjSize() << ", " << (*It2)->GetMallocCount() << ", " << (*It2)->GetFreeCount() << ", " << (*It2)->GetObjSize() * (*It2)->GetMallocCount() / (1024.0 * 1024) << "M" << std::endl;
            }
        }

        return std::move(ss.str());
    }
private:
    MapDMRapidInfo m_mapDMRapidInfo;
    std::mutex m_lock;
};

template<class T, int S>
class CDMRapidPool {
public:
    typedef T OBJTYPE;

    typedef struct tagRapidData {
        uint32_t dwUse : 1;
        uint32_t dwIndex : 15;
        uint32_t dwFlag : 16;
        char szData[sizeof(OBJTYPE)];
    } SRapidData;

    static const int SIZE = S;

    CDMRapidPool(uint16_t wIndex = 0)
        : m_wIndex(wIndex), m_wFirstFlag(0), m_qwFreeCount(0) {
        for (int i = 0; i < SIZE; ++i) {
            m_stRapidData[i].dwUse = 0;
            m_stRapidData[i].dwIndex = m_wIndex;
            m_stRapidData[i].dwFlag = i + 1;
        }

        m_qwFreeCount = SIZE;
    }

    ~CDMRapidPool() {
        assert(IsFull());
    }
public:
    virtual uint64_t GetFreeCount(void)
    {
        return m_qwFreeCount;
    }

    virtual uint64_t GetMallocCount(void)
    {
        return SIZE;
    }

    virtual const char* GetObjName(void)
    {
        return typeid(OBJTYPE).name();
    }

    virtual uint64_t GetObjSize(void)
    {
        return sizeof(OBJTYPE);
    }
public:
    template<typename... Args>
    inline OBJTYPE* FetchObj(Args&&... args) {
        if (Empty()) {
            return NULL;
        }

        assert(m_wFirstFlag < SIZE);
        SRapidData* p = &m_stRapidData[m_wFirstFlag];

        if (p->dwUse) {
            abort();
            return NULL;
        }

        assert(p->dwIndex == m_wIndex);
        m_wFirstFlag = p->dwFlag;
        --m_qwFreeCount;
        p->dwUse = 1;
        assert(m_qwFreeCount >= 0 && m_qwFreeCount <= SIZE);
        return new (p->szData) T(std::forward<Args>(args)...);
    }

    inline void ReleaseObj(OBJTYPE* tObj) {
        SRapidData* p = GetRapidData(tObj);

        if (!p->dwUse) {
            abort();
            return;
        }

        assert(p->dwIndex == m_wIndex);
        assert(p >= &m_stRapidData[0] && p <= &m_stRapidData[SIZE - 1] &&
            (((char*)p - (char*)&m_stRapidData[0]) % sizeof(SRapidData) == 0));
        p->dwFlag = m_wFirstFlag;
        m_wFirstFlag = p - m_stRapidData;
        ++m_qwFreeCount;
        p->dwUse = 0;
        assert(m_qwFreeCount >= 0 && m_qwFreeCount <= SIZE);
        tObj->~T();
    }

    inline bool Empty() {
        return 0 == m_qwFreeCount;
    }

    inline bool IsFull() {
        return SIZE == m_qwFreeCount;
    }

    static inline SRapidData* GetRapidData(OBJTYPE* tObj) {
        return (SRapidData*)((char*)tObj - offsetof(SRapidData, szData));
    }

private:
    uint16_t m_wIndex;
    uint16_t m_wFirstFlag;
    uint64_t m_qwFreeCount;
    SRapidData m_stRapidData[SIZE];
};


template<class T, int S = 1000, int I = 1000>
class CDynamicRapidPool
    : public IDMRapidInfo
{
public:
    typedef CDynamicRapidPool<T, S, I>  CThisPool;
    typedef CDMRapidPool<T, S>            CBaseRapidPool;
    typedef typename CBaseRapidPool::OBJTYPE     OBJTYPE;
    typedef typename CBaseRapidPool::SRapidData SRapidData;
    static const int SIZE = S;
    static const int INDEX = I;

    static_assert(SIZE < 65535 && INDEX < 32767, "SIZE Must < 65535, INDEX Must < 32767!");

    CDynamicRapidPool()
        : m_oDefaultRapidPool(0) {
        memset(m_arrGrowRapidPool, 0, sizeof(m_arrGrowRapidPool));

        CDMRapidFactory::Instance()->RegPool(this);
    }

    ~CDynamicRapidPool() {
        for (int i = 0; i < INDEX; ++i) {
            delete m_arrGrowRapidPool[i];
        }

        CDMRapidFactory::Instance()->UnRegPool(this);
    }
public:
    virtual uint64_t GetFreeCount(void)
    {
        uint64_t qwFreeCount = m_oDefaultRapidPool.GetFreeCount();

        for (int i = 0; i < INDEX; ++i) {
            if (NULL == m_arrGrowRapidPool[i]) {
                break;
            }
            qwFreeCount += m_arrGrowRapidPool[i]->GetFreeCount();
        }
        return qwFreeCount;
    }
    virtual uint64_t GetMallocCount(void)
    {
        uint64_t qwMallocCount = m_oDefaultRapidPool.GetMallocCount();

        for (int i = 0; i < INDEX; ++i) {
            if (NULL == m_arrGrowRapidPool[i]) {
                break;
            }
            qwMallocCount += m_arrGrowRapidPool[i]->GetMallocCount();
        }
        return qwMallocCount;
    }

    virtual const char* GetObjName(void)
    {
        return typeid(OBJTYPE).name();
    }

    virtual uint64_t GetObjSize(void)
    {
        return sizeof(OBJTYPE);
    }
public:
    template<typename... Args>
    inline OBJTYPE* FetchObj(Args&&... args) {
        if (!m_oDefaultRapidPool.Empty()) {
            return m_oDefaultRapidPool.FetchObj(std::forward<Args>(args)...);
        }

        for (int i = 0; i < INDEX; ++i) {
            if (NULL == m_arrGrowRapidPool[i]) {
                m_arrGrowRapidPool[i] = new CBaseRapidPool(i + 1);

                if (!m_arrGrowRapidPool[i]->Empty()) {
                    return m_arrGrowRapidPool[i]->FetchObj(std::forward<Args>(args)...);
                }
            }
            else if (!m_arrGrowRapidPool[i]->Empty()) {
                return m_arrGrowRapidPool[i]->FetchObj(std::forward<Args>(args)...);
            }
        }

        assert(0);
        return NULL;
    }

    inline void ReleaseObj(OBJTYPE* obj) {
        if (NULL == obj) {
            return;
        }

        SRapidData* p = CBaseRapidPool::GetRapidData(obj);

        if (0 == p->dwIndex) {
            m_oDefaultRapidPool.ReleaseObj(obj);
            return;
        }

        assert(p->dwIndex < INDEX + 1);
        assert(m_arrGrowRapidPool[p->dwIndex - 1]);
        m_arrGrowRapidPool[p->dwIndex - 1]->ReleaseObj(obj);
    }
private:

    CBaseRapidPool  m_oDefaultRapidPool;
    CBaseRapidPool* m_arrGrowRapidPool[INDEX];
};

template<typename T, int S = 10000, int I = 1000>
inline auto& DMPool()
{
    thread_local CDynamicRapidPool<T, S, I> oPool;
    return oPool;
}

template<typename T, typename... Args>
inline T* DMNew(Args&& ... args)
{
    return DMPool<T>().FetchObj(std::forward<Args>(args)...);
}

template<typename T>
inline void DMDelete(T* data)
{
    DMPool<T>().ReleaseObj(data);
}

inline std::string DMGetPoolInfo()
{
    return std::move(CDMRapidFactory::Instance()->Print());
}


template<typename T>
struct DMPoolDeleter
{

    inline void operator()(T* f) const
    {
        if (f)
        {
            DMDelete(f);
        }
    }
};

#endif // __DMRAPIDPOOL_H_INCLUDE__
