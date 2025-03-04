
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

#ifndef __DMTHREAD_H_INCLUDE__
#define __DMTHREAD_H_INCLUDE__

#include "dmos.h"

class IDMThread
{
public:
    virtual ~IDMThread() {}
    virtual void ThrdProc() = 0;
    virtual void Terminate() = 0;
};

class IDMThreadCtrl
{
public:
    virtual ~IDMThreadCtrl() {}
    virtual void Resume() = 0;
    virtual void Suspend() = 0;
    virtual void Stop() = 0;
    virtual bool Kill( unsigned int dwExitCode ) = 0;
    virtual bool WaitFor( unsigned int dwWaitTime = -1 ) = 0;
    virtual unsigned int GetThreadID() = 0;
    virtual IDMThread* GetThread() = 0;
    virtual void Release() = 0;
};

class CDMThreadCtrl : public IDMThreadCtrl
{
public:
    CDMThreadCtrl()
    {
#ifdef _WIN32
        m_bIsStop       = true;
        m_bNeedWaitFor  = true;
        m_hThread       = INVALID_HANDLE_VALUE;
        m_dwThreadID    = -1;
        m_poThread      = NULL;
#else
        m_bIsStop       = true;
        m_bNeedWaitFor  = true;
        m_ID            = 0;
        m_poThread      = NULL;
#endif
    }

    virtual ~CDMThreadCtrl()
    {
    }

public:
    virtual void Resume( void )
    {
#ifdef _WIN32
        ResumeThread( m_hThread );
#else
        DMASSERT( 0 );
#endif
    }

    virtual void Suspend()
    {
#ifdef _WIN32
        SuspendThread( m_hThread );
#else
        DMASSERT( 0 );
#endif
    }

    virtual void Stop( void )
    {
#ifdef _WIN32
        m_poThread->Terminate();
#else
        m_poThread->Terminate();
#endif
    }

    virtual bool Kill( unsigned int dwExitCode )
    {
#ifdef _WIN32

        if ( INVALID_HANDLE_VALUE == m_hThread )
        {
            return false;
        }

        if ( !TerminateThread( m_hThread, dwExitCode ) )
        {
            return false;
        }

        CloseHandle( m_hThread );
        m_hThread = INVALID_HANDLE_VALUE;
        return true;
#else
        pthread_cancel( m_ID );
        return true;
#endif
    }

    virtual bool WaitFor( unsigned int dwWaitTime = INFINITE )
    {
#ifdef _WIN32

        if ( !m_bNeedWaitFor || INVALID_HANDLE_VALUE == m_hThread )
        {
            return false;
        }

        unsigned int dwRet = WaitForSingleObject( m_hThread, dwWaitTime );
        CloseHandle( m_hThread );
        m_hThread = INVALID_HANDLE_VALUE;
        m_bIsStop = true;

        if ( WAIT_OBJECT_0 == dwRet )
        {
            return true;
        }

        return false;
#else

        if ( false == m_bNeedWaitFor )
        {
            return false;
        }

        m_bIsStop = true;
        pthread_join( m_ID, NULL );
        m_ID = -1;
        return true;
#endif
    }

    virtual void Release( void )
    {
        delete this;
    }

    virtual unsigned int GetThreadID( void )
    {
#ifdef _WIN32
        return m_dwThreadID;
#else
        return ( unsigned int )m_ID;
#endif
    }

    virtual IDMThread* GetThread( void )
    {
        return m_poThread;
    }

#ifdef _WIN32
    static unsigned int __stdcall StaticThreadFunc( void* arg )
#else
    static void* StaticThreadFunc( void* arg )
#endif
    {
#ifdef _WIN32
        CDMThreadCtrl* poCtrl = ( CDMThreadCtrl* )arg;
        poCtrl->m_bIsStop = false;
        poCtrl->m_poThread->ThrdProc();
        return 0;
#else
        CDMThreadCtrl* poCtrl = ( CDMThreadCtrl* )arg;
        pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, 0 );
        pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, 0 );
        sigset_t new_set, old_set;
        sigemptyset( &new_set );
        sigemptyset( &old_set );
        sigaddset( &new_set, SIGHUP );
        sigaddset( &new_set, SIGINT );
        sigaddset( &new_set, SIGQUIT );
        sigaddset( &new_set, SIGTERM );
        sigaddset( &new_set, SIGUSR1 );
        sigaddset( &new_set, SIGUSR2 );
        sigaddset( &new_set, SIGPIPE );
        pthread_sigmask( SIG_BLOCK, &new_set, &old_set );

        if ( !poCtrl->m_bNeedWaitFor )
        {
            pthread_detach( pthread_self() );
        }

        poCtrl->m_bIsStop = false;
        poCtrl->m_poThread->ThrdProc();
        return NULL;
#endif
    }

    bool Start( IDMThread* poThread, bool bNeedWaitFor = true,
                bool bSuspend = false )
    {
#ifdef _WIN32
        m_bNeedWaitFor = bNeedWaitFor;
        m_poThread = poThread;

        if ( bSuspend )
        {
            m_hThread = ( HANDLE )_beginthreadex( 0, 0, StaticThreadFunc, this,
                                                  CREATE_SUSPENDED, &m_dwThreadID );
        }
        else
        {
            m_hThread = ( HANDLE )_beginthreadex( 0, 0, StaticThreadFunc, this, 0,
                                                  &m_dwThreadID );
        }

        if ( INVALID_HANDLE_VALUE == m_hThread )
        {
            return false;
        }

        return true;
#else
        m_bNeedWaitFor = bNeedWaitFor;
        m_poThread = poThread;

        if ( 0 != pthread_create( &m_ID, NULL, ( void* ( * )( void* ) )StaticThreadFunc,
                                  this ) )
        {
            return false;
        }

        return true;
#endif
    }

protected:
#ifdef _WIN32
    volatile bool   m_bIsStop;
    bool            m_bNeedWaitFor;
    HANDLE          m_hThread;
    unsigned int    m_dwThreadID;
    IDMThread*        m_poThread;
#else
    volatile bool   m_bIsStop;
    pthread_t       m_ID;
    IDMThread*        m_poThread;
    bool            m_bNeedWaitFor;
#endif
};

inline IDMThreadCtrl* CreateThreadCtrl()
{
    return new CDMThreadCtrl;
}

#endif // __DMTHREAD_H_INCLUDE__
