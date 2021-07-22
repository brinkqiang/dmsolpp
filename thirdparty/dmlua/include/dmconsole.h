
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

#ifndef __DMCONSOLE_H_INCLUDE__
#define __DMCONSOLE_H_INCLUDE__

#include "dmos.h"
#include "dmsingleton.h"

class IDMConsoleSink
{
public:
    virtual ~IDMConsoleSink() {};

    virtual void OnCloseEvent() {};
};

class HDMConsoleMgr : public TSingleton<HDMConsoleMgr>
{
    friend class TSingleton<HDMConsoleMgr>;
public:
    void SetHandlerHook( IDMConsoleSink* pSink )
    {
        m_pConsoleSink = pSink;
#ifdef WIN32

        if ( 0 == SetConsoleCtrlHandler( ( PHANDLER_ROUTINE )
                                         &HDMConsoleMgr::OnConsoleEvent, true ) )
        {
            DMASSERT( 0 );
        }

#else
        m_phSigHandler = signal( SIGINT, &HDMConsoleMgr::OnConsoleEvent );

        if ( SIG_ERR == m_phSigHandler )
        {
            DMASSERT( 0 );
        }

#endif
    }

    void OnCloseEvent()
    {
        if ( m_bOnce && m_pConsoleSink )
        {
            m_bOnce = false;
            m_pConsoleSink->OnCloseEvent();
        }
    }

#ifdef WIN32
    static BOOL WINAPI OnConsoleEvent( UINT32 dwEventType )
    {
        switch ( dwEventType )
        {
        case CTRL_C_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
        {
            HDMConsoleMgr::Instance()->OnCloseEvent();
        }
        break;

        default:
            DMASSERT( 0 );
            break;
        }

        return TRUE;
    }
#else
    static void OnConsoleEvent( int nEventType )
    {
        switch ( nEventType )
        {
        case SIGINT:
        {
            HDMConsoleMgr::Instance()->OnCloseEvent();
        }
        break;

        default:
            DMASSERT( 0 );
            break;
        }
    }
private:
    sighandler_t m_phSigHandler;
#endif

public:
    HDMConsoleMgr()
    {
#ifdef WIN32
        m_pConsoleSink = NULL;
        m_bOnce = true;
#else
        m_phSigHandler = NULL;
        m_pConsoleSink = NULL;
        m_bOnce = true;
#endif
    }

    ~HDMConsoleMgr()
    {
    }

private:
    IDMConsoleSink*   m_pConsoleSink;
    bool            m_bOnce;
};

#endif // __DMCONSOLE_H_INCLUDE__
