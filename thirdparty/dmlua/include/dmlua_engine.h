
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

#ifndef __DMLUA_ENGINE_H_INCLUDE__
#define __DMLUA_ENGINE_H_INCLUDE__

#include <assert.h>
#include <string.h>
#include <time.h>

#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <limits>
#include "lua.hpp"
#include "tolua++.h"

#include "dmlua_typeid.h"
#include "dmlua_luaresult.h"

#include "dmtypes.h"
#include "dmparser.h"
#include "dmsingleton.h"
#include "dmutil.h"

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

#ifdef WIN32
#else
#include <sys/time.h>
#endif

#include "sol/sol.hpp"

inline char* tolua_SafeStrCopy(char* des, const char* src, size_t max_len)
{
    // initialize for check below
    if (NULL == src)
    {
        des[0] = '\0';
        return des;
    }

    des[max_len - 1] = 0;
    return strnlen(src, max_len) < max_len ? strcpy(des, src) : strncpy(des,
        src, max_len - 1);
}

template <size_t N>
inline char* tolua_SafeStrCopy(char(&des)[N], const char* src)
{
    return tolua_SafeStrCopy(des, src, sizeof(des));
}

template <size_t N>
inline void tolua_ZeroString(char(&des)[N]) throw()
{
    des[0] = '\0';
    des[sizeof(des) - 1] = '\0';
}

template <size_t N>
inline void tolua_SafeSprintf(char(&des)[N], const char* format,
    ...) throw()
{
    va_list args;
    va_start(args, format);
    vsnprintf(des, sizeof(des) - 1, format, args);
    va_end(args);
    des[sizeof(des) - 1] = '\0';
}

#ifdef WIN32
inline size_t tolua_StrNLen(const char* src, size_t max_len)
{
    size_t i;
    const char* ptr = src;

    for (i = 0; i < max_len; i++)
    {
        if ('\0' == *ptr)
        {
            return i;
        }

        ptr++;
    }

    return max_len;
}
#else
inline size_t tolua_StrNLen(const char* src, size_t max_len)
{
    return strnlen(src, max_len);
}
#endif

inline char*
tolua_strtok_r(char* ptr, const char* sep, char** end)
{
    if (!ptr)
        /* we got NULL input so then we get our last position instead */
    {
        ptr = *end;
    }

    /* pass all letters that are including in the separator string */
    while (*ptr && strchr(sep, *ptr))
    {
        ++ptr;
    }

    if (*ptr)
    {
        /* so this is where the next piece of string starts */
        char* start = ptr;
        /* set the end pointer to the first byte after the start */
        *end = start + 1;

        /* scan through the string to find where it ends, it ends on a
        null byte or a character that exists in the separator string */
        while (**end && !strchr(sep, **end))
        {
            ++* end;
        }

        if (**end)
        {
            /* the end is not a null byte */
            **end = '\0';  /* zero terminate it! */
            ++* end;        /* advance the last pointer to beyond the null byte */
        }

        return start; /* return the position where the string starts */
    }

    /* we ended up on a null byte, there are no more strings to find! */
    return NULL;
}

#ifdef WIN32

struct __timezone
{
    int  tz_minuteswest; /* minutes W of Greenwich */
    int  tz_dsttime;     /* type of dst correction */
};

struct __timeval
{
    long    tv_sec;         /* seconds */
    long    tv_usec;        /* and microseconds */
};

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

typedef union
{
    uint64_t ft_scalar;
    FILETIME ft_struct;
} FT;

static inline int gettimeofday(struct __timeval* tv, struct __timezone* tz)
{
    FT ft;
    static int tzflag = 0;

    if (NULL != tv)
    {
        GetSystemTimeAsFileTime(&ft.ft_struct);
        ft.ft_scalar /= 10;
        ft.ft_scalar -= DELTA_EPOCH_IN_MICROSECS;
        tv->tv_sec = (long)(ft.ft_scalar / 1000000UL);
        tv->tv_usec = (long)(ft.ft_scalar % 1000000UL);
    }

    if (NULL != tz)
    {
        if (!tzflag)
        {
            _tzset();
            tzflag++;
        }

        tz->tz_minuteswest = _timezone / 60;
        tz->tz_dsttime = _daylight;
    }

    return 0;
}

#endif

inline uint32_t GetTickCount32()
{
#ifdef WIN32
    struct __timeval tv = { 0 };
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#else
    struct timeval tv = { 0 };
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#endif
}

//#define DMLUA_CALL lua_pcall
//#define DMLUA_CALL(L,n,r,f) (lua_call(L,n,r),0)
#define DMLUA_CALL(L,n,r,f) (lua_pcall(L,n,r,f))

#define LUA_CHECK_FUNCTION(luaS, func) \
    CLuaStateGuard oGuard(luaS, func);\
    do{ if (LuaCheckFunction(luaS, func)){ OnUserError(luaS, func); return -1;} }while(0)

#define LUA_CHECKT_FUNCTION(luaS, func, ret) \
    CLuaStateGuard oGuard(luaS, func);\
    do{ if (LuaCheckFunction(luaS, func)){ OnUserError(luaS, func); return ret;} }while(0)

#define LUA_CALL_FUNCTION(luaS, func, arg, count) \
    do{ OnEventLuaCallStart();if (DMLUA_CALL(luaS, arg, count, 0)){ OnEventLuaCallEnd();OnScriptError(luaS, func);return -1;}; OnEventLuaCallEnd();} while(0)

#define LUA_CALLT_FUNCTION(luaS, func, arg, count, ret) \
    do{ OnEventLuaCallStart();if (DMLUA_CALL(luaS, arg, count, 0)){ OnEventLuaCallEnd();OnScriptError(luaS, func);return ret;}; OnEventLuaCallEnd();} while(0)

#define LUA_CALL_FUNCTION_NOEVENT(luaS, func, arg, res) \
    do{ if (DMLUA_CALL(luaS, arg, res, 0)){ OnScriptError(luaS, func);return -1;}; } while(0)

class CLuaStateGuard
{

public:
    explicit CLuaStateGuard(lua_State* pLuaS, const char* func)
        : m_pLuaS(pLuaS), m_func(func)
    {
        m_nTop = lua_gettop(m_pLuaS);
        /*
        if (m_nTop)
        {
            fprintf(stderr, "function: [%s] found top: [%d] error\n", m_func, m_nTop);
        }
        */
    }

    ~CLuaStateGuard()
    {
        lua_settop(m_pLuaS, m_nTop);
    }
private:
    lua_State* m_pLuaS;
    int           m_nTop;
    const char* m_func;
};

class CLuaFunctionExtractQuick
{
public:
    CLuaFunctionExtractQuick(const char* func, const char* sep)
        : m_pSep(sep), m_pEndNode(NULL)
    {
        tolua_SafeStrCopy(szFunc, func);
    }

    char* First()
    {
        char* pStartNode = tolua_strtok_r(szFunc, m_pSep, &m_pEndNode);

        if (NULL == pStartNode)
        {
            return NULL;
        }

        return pStartNode;
    }

    char* Next()
    {
        char* pStartNode = tolua_strtok_r(NULL, m_pSep, &m_pEndNode);

        if (NULL == pStartNode)
        {
            return NULL;
        }

        return pStartNode;
    }
private:
    char        szFunc[MAX_PATH];
    char* m_pEndNode;
    const char* m_pSep;
};

class CLuaFunctionExtract
{
public:
    CLuaFunctionExtract(const char* func, const char* sep)
        : m_pSep(sep), m_pEndNode(NULL)
    {
        strFunc.assign(func);
    }

    char* first()
    {
        char* pStartNode = tolua_strtok_r(&strFunc[0], m_pSep, &m_pEndNode);

        if (NULL == pStartNode)
        {
            return NULL;
        }

        return pStartNode;
    }

    char* next()
    {
        char* pStartNode = tolua_strtok_r(NULL, m_pSep, &m_pEndNode);

        if (NULL == pStartNode)
        {
            return NULL;
        }

        return pStartNode;
    }
private:
    std::string strFunc;
    char* m_pEndNode;
    const char* m_pSep;
};

// tolua_begin
// tolua_end
template <typename T>
struct LuaReader
{
    static inline T Read(lua_State* L, int index)
    {
        if (CluaTypeid::Instance().get_name<T>())
        {
            return *(T*)(tolua_tousertype(L, index, NULL));
        }
        else
        {
            return *(T*)(tolua_touserdata(L, index, NULL));
        }
    }
};

template <typename T>
struct LuaReader<T*>
{
    static inline T* Read(lua_State* L, int index)
    {
        if (CluaTypeid::Instance().get_name<T>())
        {
            return (T*)tolua_tousertype(L, index, NULL);
        }
        else
        {
            return (T*)tolua_touserdata(L, index, NULL);
        }
    }
};

template <typename T>
struct LuaReader<T&>
{
    static inline T& Read(lua_State* L, int index)
    {
        if (CluaTypeid::Instance().get_name<T>())
        {
            return *(T*)tolua_tousertype(L, index, NULL);
        }
        else
        {
            return *(T*)tolua_touserdata(L, index, NULL);
        }
    }
};

template <>
struct LuaReader<void>
{
    static inline void Read(lua_State* L, int index)
    {

    }
};

template <>
struct LuaReader<void*>
{
    static inline void* Read(lua_State* L, int index)
    {
        return tolua_touserdata(L, index, NULL);
    }
};

template <>
struct LuaReader<char>
{
    static inline char Read(lua_State* L, int index)
    {
        return (char)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<unsigned char>
{
    static inline unsigned char Read(lua_State* L, int index)
    {
        return (unsigned char)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<int16_t>
{
    static inline int16_t Read(lua_State* L, int index)
    {
        return (int16_t)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<uint16_t>
{
    static inline uint16_t Read(lua_State* L, int index)
    {
        return (uint16_t)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<int>
{
    static inline int32_t Read(lua_State* L, int index)
    {
        return (int32_t)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<uint32_t>
{
    static inline uint32_t Read(lua_State* L, int index)
    {
        return (uint32_t)tolua_tointeger(L, index, 0);
    }
};

//template <>
//struct LuaReader<long>
//{
//    static inline long Read(lua_State* L, int index)
//    {
//        return (long)tolua_tointeger(L, index, 0);
//    }
//};
//
//template <>
//struct LuaReader<unsigned long>
//{
//    static inline unsigned long Read(lua_State* L, int index)
//    {
//        return (unsigned long)tolua_tointeger(L, index, 0);
//    }
//};

template <>
struct LuaReader<int64_t>
{
    static inline int64_t Read(lua_State* L, int index)
    {
        return (int64_t)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<uint64_t>
{
    static inline uint64_t Read(lua_State* L, int index)
    {
        return (uint64_t)tolua_tointeger(L, index, 0);
    }
};

template <>
struct LuaReader<float>
{
    static inline float Read(lua_State* L, int index)
    {
        return (float)tolua_tonumber(L, index, 0);
    }
};

template <>
struct LuaReader<double>
{
    static inline double Read(lua_State* L, int index)
    {
        return (double)tolua_tonumber(L, index, 0);
    }
};

template <>
struct LuaReader<const char*>
{
    static inline const char* Read(lua_State* L, int index)
    {
        return tolua_tostring(L, index, "");
    }
};

template <>
struct LuaReader<char*>
{
    static inline char* Read(lua_State* L, int index)
    {
        return const_cast<char*>(tolua_tostring(L, index, ""));
    }
};

template <>
struct LuaReader<bool>
{
    static inline bool Read(lua_State* L, int index)
    {
        if (lua_isnil(L, index))
        {
            return false;
        }

        if (lua_isboolean(L, index))
        {
            return tolua_toboolean(L, index, 0) != 0;
        }
        else
        {
            return tolua_tonumber(L, index, 0) != 0;
        }
    }
};

template <typename T>
static inline T LuaPop(lua_State* L)
{
    T ret = LuaReader<T>::Read(L, -1);
    lua_pop(L, 1);
    return ret;
}

static inline void LuaPop(lua_State* L)
{
    lua_pop(L, 1);
}

class CDMLuaEngine : public CDMSafeSingleton<CDMLuaEngine>
{
    friend class CDMSafeSingleton<CDMLuaEngine>;
public:

    typedef struct tagFileInfo
    {
        std::string strFullPathFile;
        std::string strFullPath;
        std::string strModuleName;
    } SFileInfo;

public:
    CDMLuaEngine()
        : m_pLuaS(luaL_newstate()), m_dwStartTime(0), m_bStartTime(false)
    {
        luaL_openlibs(m_pLuaS);
    }

    virtual ~CDMLuaEngine()
    {
        if (m_pLuaS)
        {
            lua_close(m_pLuaS);
            m_pLuaS = NULL;
        }
    }

    void SetRootPath(const std::string& strPath)
    {
        m_strSrcPath = strPath;
    }

    void Swap(CDMLuaEngine& oEngine)
    {
        std::swap(m_pLuaS, oEngine.m_pLuaS);
        std::swap(m_vecFileInfo, oEngine.m_vecFileInfo);
        std::swap(m_strSrcPath, oEngine.m_strSrcPath);
        std::swap(m_strCwd, oEngine.m_strCwd);
        std::swap(m_dwStartTime, oEngine.m_dwStartTime);
        std::swap(m_vecFunction, oEngine.m_vecFunction);
        std::swap(m_bStartTime, oEngine.m_bStartTime);
    }

    void RunLuagc()
    {
        lua_gc(m_pLuaS, LUA_GCCOLLECT, 0);
    }

    uint64_t GetLuagc()
    {
        return lua_gc(m_pLuaS, LUA_GCCOUNT, 0) * 1024L + lua_gc(m_pLuaS,
            LUA_GCCOUNTB, 0);
    }

    sol::state_view GetSol(){ return sol::state_view(m_pLuaS); }

    lua_State* GetState()
    {
        return m_pLuaS;
    }

    bool DoString(const char* data)
    {
        CLuaStateGuard oGuard(m_pLuaS, "DoString");
        int nRet = luaL_dostring(m_pLuaS, data);

        if (0 != nRet)
        {
            OnScriptError(m_pLuaS, "DoString");
        }

        return 0 == nRet ? true : false;
    }
    bool DoFile(const char* data)
    {
        CLuaStateGuard oGuard(m_pLuaS, "DoFile");
        int nRet = luaL_dofile(m_pLuaS, data);

        if (0 != nRet)
        {
            OnScriptError(m_pLuaS, "DoFile");
        }

        return 0 == nRet ? true : false;
    }

    void AddLuaPath(const std::string& strPath)
    {
        CLuaStateGuard oGuard(m_pLuaS, "AddPath");

        lua_getglobal(m_pLuaS, "package");
        lua_getfield(m_pLuaS, -1, "path");
        const char* curPath = lua_tostring(m_pLuaS, -1);
#ifdef _WIN32
        lua_pushfstring(m_pLuaS, "%s;%s\\?.lua", curPath, strPath.c_str());
#else
        lua_pushfstring(m_pLuaS, "%s;%s/?.lua", curPath, strPath.c_str());
#endif
        lua_setfield(m_pLuaS, -3, "path");
    }

    void AddLuaCPath(const std::string& strPath)
    {
        CLuaStateGuard oGuard(m_pLuaS, "AddCPath");

        lua_getglobal(m_pLuaS, "package");
        lua_getfield(m_pLuaS, -1, "cpath");
        const char* curPath = lua_tostring(m_pLuaS, -1);
#ifdef _WIN32
        lua_pushfstring(m_pLuaS, "%s;%s\\?.dll", curPath, strPath.c_str());
#else
        lua_pushfstring(m_pLuaS, "%s;%s/?.so", curPath, strPath.c_str());
#endif
        lua_setfield(m_pLuaS, -3, "cpath");
    }

    int AddModule(lua_CFunction f)
    {
        m_vecFunction.push_back(f);

        return 0;
    }

    bool LoadScript(const std::string& strName)
    {
        __ParserBegin();
        __LoadScript(strName);
        __ParserEnd();
        return true;
    }

    bool LoadScript()
    {
        for (auto it : m_vecFunction)
        {
            it(GetState());
        }

        __SetSrcDirectory(!m_strSrcPath.empty() ? m_strSrcPath : __GetScriptPath());
        __ParserBegin();
        __ParserFiles(m_strSrcPath, "");
        __LoadScriptAll();
        __ParserEnd();
        return true;
    }

    bool ReloadScript()
    {
        CDMLuaEngine oEngine;
        oEngine.SetRootPath(m_strSrcPath);

        for (auto it : m_vecFunction)
        {
            oEngine.AddModule(it);
        }

        oEngine.AddLuaPath(m_strSrcPath);

        if (!oEngine.LoadScript())
        {
            goto FAIL;
        }

        oEngine.Swap(*this);

        return true;
    FAIL:
        return false;
    }

    static inline int LuaCheckFunction(lua_State* luaS, const char* func)
    {
        CLuaFunctionExtractQuick oLuaExtract(func, ".");
        char* start = oLuaExtract.First();

        if (NULL == start)
        {
            return -1;
        }

        char* next = oLuaExtract.Next();

        if (NULL == next)
        {
            return tolua_isGlobalFunction(luaS, start);
        }

        if (tolua_isGlobalTable(luaS, start))
        {
            return -1;
        }

        char* end = oLuaExtract.Next();

        if (NULL == end)
        {
            return tolua_isFunction(luaS, next);
        }

        do
        {
            if (tolua_isTable(luaS, next))
            {
                return -1;
            }

            next = end;
            end = oLuaExtract.Next();
        } while (end);

        if (tolua_isFunction(luaS, next))
        {
            return -1;
        }

        return 0;
    }

    template<typename T>
    static inline void LuaPush(lua_State* luaS, T& t)
    {
        if (CluaTypeid::Instance().get_name<T>())
        {
            tolua_pushusertype(luaS, (void*)(&t),
                CluaTypeid::Instance().get_name<T>());
        }
        else
        {
            tolua_pushuserdata(luaS, (void*)(&t));
            OnUserError(luaS, typeid(T).name());
        }
    }

    template<typename T>
    static inline void LuaPush(lua_State* luaS, T*& t)
    {
        if (CluaTypeid::Instance().get_name<T>())
        {
            tolua_pushusertype(luaS, t, CluaTypeid::Instance().get_name<T>());
        }
        else
        {
            tolua_pushuserdata(luaS, (void*)(t));
            OnUserError(luaS, typeid(T).name());
        }
    }

    static inline void LuaPush(lua_State* luaS, std::string& t)
    {
        tolua_pushlstring(luaS, t.c_str(), t.size());
    }

    static inline void LuaPush(lua_State* luaS, const std::string& t)
    {
        tolua_pushlstring(luaS, t.c_str(), t.size());
    }

    static inline void LuaPush(lua_State* luaS, const char t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const uint8_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const int16_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const uint16_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const int32_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const uint32_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const int64_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const uint64_t t)
    {
        lua_pushinteger(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const float t)
    {
        tolua_pushnumber(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const double t)
    {
        tolua_pushnumber(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const char* t)
    {
        tolua_pushstring(luaS, t);
    }

    static inline void LuaPush(lua_State* luaS, const bool t)
    {
        tolua_pushboolean(luaS, t);
    }

    //////////////////////////////////////////////////////////////////////////
    template <typename T, typename... ARGS>
    void LuaPushT(T t, ARGS&& ... args)
    {
        LuaPush(m_pLuaS, t);
        LuaPushT(args ...);
    }

    void LuaPushT() {}

    template<typename ResultType, typename... ARGS>
    inline ResultType CallT(const char* func, ARGS&& ... args)
    {
        LUA_CHECKT_FUNCTION(m_pLuaS, func, ResultType());
        LuaPushT(args...);
        LUA_CALLT_FUNCTION(m_pLuaS, func, sizeof...(args), 1, ResultType());
        return LuaPop<ResultType>(m_pLuaS);
    }

    template<typename... ARGS>
    inline int Call(const char* func, ARGS&& ... args)
    {
        LUA_CHECK_FUNCTION(m_pLuaS, func);
        LuaPushT(args...);
        LUA_CALL_FUNCTION(m_pLuaS, func, sizeof...(args), 0);

        return 0;
    }

    //////////////////////////////////////////////////////////////////////////
    //    template <typename T>
    //    void XPushParam(T t)
    //    {
    //        PushLuaParam(m_pLuaS, t);
    //    }
    //    template<typename... ARGS>
    //    inline int XCall(const char* func, ARGS... args) {
    //    LUA_CHECK_FUNCTION(m_pLuaS, func);
    //    std::initializer_list<int>{([&]
    //    {
    //        XPushParam(args);
    //    }(), 0)...};
    //    LUA_CALL_FUNCTION(m_pLuaS, func, sizeof...(args), 0);
    //    return 0;
    //}
    //////////////////////////////////////////////////////////////////////////

    static inline int tolua_isGlobalTable(lua_State* luaS, const char* func)
    {
        lua_pushglobaltable(luaS);
        lua_getfield(luaS, -1, func);

        if (lua_istable(luaS, -1))
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    static inline int tolua_isFunction(lua_State* luaS, const char* func)
    {
        lua_getfield(luaS, -1, func);

        if (lua_isfunction(luaS, -1))
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    static inline int tolua_isTable(lua_State* luaS, const char* func)
    {
        lua_getfield(luaS, -1, func);

        if (lua_istable(luaS, -1))
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    static inline int tolua_isGlobalFunction(lua_State* luaS, const char* func)
    {
        lua_pushglobaltable(luaS);
        lua_getfield(luaS, -1, func);

        if (lua_isfunction(luaS, -1))
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
private:
    static inline std::string __GetScriptPath()
    {

#ifdef WIN32
        static char path[MAX_PATH];
        static bool first_time = true;

        if (first_time)
        {
            first_time = false;
            GetModuleFileNameA(0, path, sizeof(path));
            char* p = strrchr(path, '\\');
            *(p) = '\0';
            p = strrchr(path, '\\');
            *(p) = '\0';
        }

        return path;
#elif __APPLE__
        static char path[MAX_PATH];
        static bool first_time = true;

        if (first_time)
        {
            uint32_t size = sizeof(path);
            int nRet = _NSGetExecutablePath(path, &size);

            if (nRet != 0)
            {
                return "./";
            }

            char* p = strrchr(path, '/');
            *(p) = '\0';
            p = strrchr(path, '/');
            *(p) = '\0';
        }

        return path;
#else
        static char path[MAX_PATH];
        static bool first_time = true;

        if (first_time)
        {
            first_time = false;
            int nRet = readlink("/proc/self/exe", path, MAX_PATH);

            if (nRet < 0 || nRet >= MAX_PATH)
            {
                return "./";
            }

            char* p = strrchr(path, '/');
            *(p) = '\0';
            p = strrchr(path, '/');
            *(p) = '\0';
        }

        return path;
#endif
    }

    void __SetSrcDirectory(const std::string& strSrc)
    {
        m_strSrcPath = strSrc;
    }

    inline void __AddFile(const std::string& strPath,
        const std::string& strFullPathPwd, const std::string& strFullPath)
    {
        SFileInfo stFileInfo;
        stFileInfo.strFullPathFile = strPath;
        stFileInfo.strModuleName = strFullPathPwd;
        stFileInfo.strFullPath = strFullPath;
        m_vecFileInfo.push_back(stFileInfo);
    }

    inline void __ParserFiles(const std::string& strRoot,
        const std::string& strPwd)
    {
        CDirectoryParser oDirectoryParser;
        std::string strRealPath;

        if (strPwd.empty())
        {
            strRealPath = strRoot;
        }
        else
        {
            strRealPath = strRoot + PATH_DELIMITER_STR + strPwd;
        }

        if (!oDirectoryParser.Open(strRealPath.c_str()))
        {
            return;
        }

        do
        {
            char szPath[MAX_PATH] = { 0 };
            SFileAttr sAttr;
            memset(&sAttr, 0, sizeof(sAttr));

            if (!oDirectoryParser.Read(szPath, sizeof(szPath), &sAttr))
            {
                break;
            }

            std::string strFullPathPwd;

            if (strPwd.empty())
            {
                strFullPathPwd = szPath;
            }
            else
            {
                strFullPathPwd = strPwd + PATH_DELIMITER_STR + szPath;
            }

            std::string strFullPathFile = strRoot + PATH_DELIMITER_STR + strFullPathPwd;
            std::string strFullPath = strRoot + PATH_DELIMITER_STR + strPwd;

            if (sAttr.isDir)
            {
                __ParserFiles(strRoot, strFullPathPwd);
                continue;
            }

            std::string ext = strFullPathFile.substr(strFullPathFile.rfind('.') ==
                std::string::npos ? strFullPathFile.length() :
                strFullPathFile.rfind('.'));
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

            if (ext == ".lua")
            {
                std::string strModuleName = strFullPathPwd.substr(0,
                    strFullPathPwd.size() - ext.size());
                std::replace(strModuleName.begin(), strModuleName.end(), PATH_DELIMITER, '.');
                __AddFile(strFullPathFile, strModuleName, strFullPath);
            }
        } while (true);

        oDirectoryParser.Close();
        return;
    }

    void __ParserBegin()
    {
        char szPath[MAX_PATH] = { 0 };
        m_strCwd = getcwd(szPath, MAX_PATH);
        chdir(m_strSrcPath.c_str());

        m_vecFileInfo.clear();
    }

    void __LoadScriptAll()
    {
        if (!m_vecFileInfo.empty())
        {
            for (int i = 0; i < static_cast<int>(m_vecFileInfo.size()); i++)
            {
                SFileInfo& sFileInfo = m_vecFileInfo[i];

                if (!__LoadScript(sFileInfo.strModuleName))
                {
                    ;
                }
            }
        }
    }

    void __ParserEnd()
    {
        /*
        int mask = LUA_MASKCALL | LUA_MASKRET | LUA_MASKLINE | LUA_MASKCOUNT;
        lua_sethook(m_pLuaS, &FireLuaCheck, mask, 1);
        chdir(m_strCwd.c_str());
        */
    }

    bool __LoadScript(const std::string& strName)
    {
        CLuaStateGuard oGuard(m_pLuaS, strName.c_str());
        char szBuf[MAX_PATH] = { 0 };
        tolua_SafeSprintf(szBuf, "package.loaded[\"%s\"]=nil\n require \"%s\"\n",
            strName.c_str(), strName.c_str());
        int nRet = luaL_dostring(m_pLuaS, szBuf);

        if (0 != nRet)
        {
            OnScriptError(m_pLuaS, strName.c_str());
            return false;
        }
        else
        {
            return true;
        }
    }

    inline void OnEventLuaCallStart()
    {
        m_dwStartTime = GetTickCount32();
        m_bStartTime = true;
    }

    inline void OnEventLuaCallEnd()
    {
        m_dwStartTime = 0;
        m_bStartTime = false;
    }

    enum ECheckTime
    {
        eLuaCheckTime = 0,
    };

    inline void LuaCheck()
    {
        if (eLuaCheckTime && m_bStartTime)
        {
            uint32_t dwUseTime = GetTickCount32() - m_dwStartTime;

            if (dwUseTime > eLuaCheckTime)
            {
                luaL_error(m_pLuaS, "lua script timeout %d ms", dwUseTime);
            }
        }
    }

    static inline void OnUserError(lua_State* luaS, const char* name)
    {
        char szError[256];
        tolua_SafeSprintf(szError, "call Lua func error [%s] not exist\n", name);
        fprintf(stderr, szError);
    }

    static inline void OnScriptError(lua_State* luaS, const char* name)
    {
        char szError[256];
        tolua_SafeSprintf(szError, "call Lua script [%s] error [%s] \n", name,
            lua_tostring(luaS, -1));
        fprintf(stderr, szError);
    }

    //static void FireLuaCheck(lua_State* luaS, lua_Debug* ar)
    //{
    //    CDMLuaEngine* poEngine = FromLuaState(luaS);
    //    if (NULL != poEngine)
    //    {
    //        poEngine->LuaCheck();
    //    }
    //}

    //static CDMLuaEngine* FromLuaState(lua_State* luaS)
    //{
    //    return static_cast<CDMLuaEngine*>(__lua_getuserdata(luaS));
    //}

    //static void RegisterEvent(CDMLuaEngine& oEngine)
    //{
    //    assert(oEngine.GetState());

    //    __lua_setuserdata(oEngine.GetState(),  (void*)&oEngine);
    //}

protected:
    lua_State* m_pLuaS;

    typedef std::vector<SFileInfo> VecFileInfo;
    typedef VecFileInfo::iterator VecFileInfoIt;
    typedef std::vector<lua_CFunction> VecFunction;
    typedef VecFunction::iterator VecFunctionIt;

    VecFileInfo m_vecFileInfo;
    std::string m_strSrcPath;
    std::string m_strCwd;
    VecFunction m_vecFunction;
    uint32_t m_dwStartTime;
    bool m_bStartTime;
};

#endif // __DMLUA_ENGINE_H_INCLUDE__
