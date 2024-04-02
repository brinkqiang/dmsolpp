
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

#include <cstring>
#include <cassert>
#include <new>

template<class T, int S>
class CDMRapidPool
{
public:
    typedef T OBJTYPE;

    typedef struct tagRapidData
    {
        unsigned int dwUse: 1;
        unsigned int dwIndex: 15;
        unsigned int dwFlag: 16;
        char szData[sizeof( OBJTYPE )];
    } SRapidData;

    static const int SIZE = S;

    CDMRapidPool( unsigned short wIndex = 0 )
        : m_wIndex( wIndex ), m_wFirstFlag( 0 ), m_nFreeCount( 0 )
    {
        for ( int i = 0; i < SIZE; ++i )
        {
            m_stRapidData[i].dwUse = 0;
            m_stRapidData[i].dwIndex = m_wIndex;
            m_stRapidData[i].dwFlag = i + 1;
        }

        m_nFreeCount = SIZE;
    }

    ~CDMRapidPool()
    {
        assert( IsFull() );
    }

    inline OBJTYPE*  FetchObj()
    {
        if ( m_nFreeCount <= 0 )
        {
            return NULL;
        }

        assert( m_wFirstFlag < SIZE );
        SRapidData* p = &m_stRapidData[m_wFirstFlag];

        if ( p->dwUse )
        {
            abort();
            return NULL;
        }

        assert( p->dwIndex == m_wIndex );
        m_wFirstFlag = p->dwFlag;
        --m_nFreeCount;
        p->dwUse = 1;
        assert( m_nFreeCount >= 0 && m_nFreeCount <= SIZE );
        return new ( p->szData ) T();
    }

    inline void ReleaseObj( OBJTYPE* tObj )
    {
        SRapidData* p = GetRapidData( tObj );

        if ( !p->dwUse )
        {
            abort();
            return;
        }

        assert( p->dwIndex == m_wIndex );
        assert( p >= &m_stRapidData[0] && p <= &m_stRapidData[SIZE - 1] &&
                ( ( ( char* )p - ( char* )&m_stRapidData[0] ) % sizeof( SRapidData ) == 0 ) );
        p->dwFlag = m_wFirstFlag;
        m_wFirstFlag = p - m_stRapidData;
        ++m_nFreeCount;
        p->dwUse = 0;
        assert( m_nFreeCount >= 0 && m_nFreeCount <= SIZE );
        tObj->~T();
    }

    inline bool Empty()
    {
        return 0 == m_nFreeCount;
    }

    inline bool IsFull()
    {
        return SIZE == m_nFreeCount;
    }

    static inline SRapidData* GetRapidData( OBJTYPE* tObj )
    {
        return ( SRapidData* )( ( char* )tObj - offsetof( SRapidData, szData ) );
    }

private:
    unsigned short m_wIndex;
    unsigned short m_wFirstFlag;
    int m_nFreeCount;
    SRapidData m_stRapidData[SIZE];
};

template<class T, int S, int I>
class CDynamicRapidPool
{
public:
    typedef CDynamicRapidPool<T, S, I>  CThisPool;
    typedef CDMRapidPool<T, S>            CBaseRapidPool;
    typedef typename CBaseRapidPool::OBJTYPE     OBJTYPE;
    typedef typename CBaseRapidPool::SRapidData SRapidData;
    static const int SIZE = S;
    static const int INDEX = I;

    //static_assert(SIZE < 65535 && INDEX < 32767, "SIZE Must < 65535, INDEX Must < 32767!");

    CDynamicRapidPool()
        : m_oDefaultRapidPool( 0 )
    {
        memset( m_arrGrowRapidPool, 0, sizeof( m_arrGrowRapidPool ) );
    }

    ~CDynamicRapidPool()
    {
        for ( int i = 0; i < INDEX; ++i )
        {
            delete m_arrGrowRapidPool[i];
        }
    }

    inline OBJTYPE*  FetchObj()
    {
        if ( !m_oDefaultRapidPool.Empty() )
        {
            return m_oDefaultRapidPool.FetchObj();
        }

        for ( int i = 0; i < INDEX; ++i )
        {
            if ( NULL == m_arrGrowRapidPool[i] )
            {
                m_arrGrowRapidPool[i] = new CBaseRapidPool( i + 1 );

                if ( !m_arrGrowRapidPool[i]->Empty() )
                {
                    return m_arrGrowRapidPool[i]->FetchObj();
                }
            }
            else if ( !m_arrGrowRapidPool[i]->Empty() )
            {
                return m_arrGrowRapidPool[i]->FetchObj();
            }
        }

        assert( 0 );
        return NULL;
    }

    inline void ReleaseObj( OBJTYPE* obj )
    {
        if ( NULL == obj )
        {
            return;
        }

        SRapidData* p = CBaseRapidPool::GetRapidData( obj );

        if ( 0 == p->dwIndex )
        {
            m_oDefaultRapidPool.ReleaseObj( obj );
            return;
        }

        assert( p->dwIndex < INDEX + 1 );
        assert( m_arrGrowRapidPool[p->dwIndex - 1] );
        m_arrGrowRapidPool[p->dwIndex - 1]->ReleaseObj( obj );
    }
private:

    CBaseRapidPool  m_oDefaultRapidPool;
    CBaseRapidPool* m_arrGrowRapidPool[INDEX];
};

#endif // __DMRAPIDPOOL_H_INCLUDE__
