
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

#ifndef __DMUTIL_H_INCLUDE__
#define __DMUTIL_H_INCLUDE__

#include "dmos.h"

#include <string>
#include <atomic>
#include <mutex>

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

// tolua_begin

#ifdef _WIN32
static inline struct tm *localtime_r(const time_t *timep, struct tm *result)
{
    localtime_s(result, timep);
    return result;
}
static inline struct tm *gmtime_r(const time_t *timep, struct tm *result)
{
    gmtime_s(result, timep);
    return result;
}
#endif

static inline std::string DMFormatIP(unsigned int dwIP)
{
    sockaddr_in s;
    s.sin_family = AF_INET;
    s.sin_addr.s_addr = dwIP;
    return inet_ntoa(s.sin_addr);
}

static inline unsigned int DMFormatIP(const std::string &strIp)
{
    return inet_addr(strIp.c_str());
}

static inline unsigned short DMFormatPort(const std::string &strPort)
{
    return htons(atoi(strPort.c_str()));
}

static inline unsigned short DMFormatPort(unsigned short wPort)
{
    return htons(wPort);
}

static inline std::string DMFormatDateTime(time_t tVal = time(0),
                                           const char *pFormat = "%Y-%m-%d %H:%M:%S")
{
    struct tm Tm = {0};

    if (localtime_r(&tVal, &Tm))
    {
        char szBuf[128];
        strftime(szBuf, sizeof(szBuf), pFormat, &Tm);
        return szBuf;
    }

    return "";
}

static inline time_t DMFormatDateTime(const std::string &strTime,
                                      const char *pFormat = "%d-%d-%d %d:%d:%d")
{
    time_t ret = 0;
    struct tm tmMake = {0};

    if (6 == sscanf(strTime.c_str(), pFormat, &tmMake.tm_year, &tmMake.tm_mon,
                    &tmMake.tm_mday, &tmMake.tm_hour, &tmMake.tm_min, &tmMake.tm_sec))
    {
        tmMake.tm_year -= 1900;
        tmMake.tm_mon -= 1;
        ret = mktime(&tmMake);
    }

    return ret;
}

static inline bool DMIsDirectory(const char *dir_name)
{
#ifdef _WIN32
    int ret = GetFileAttributesA(dir_name);

    if (ret == -1)
    {
        return false;
    }

    return !!(FILE_ATTRIBUTE_DIRECTORY & ret);
#else
    struct stat fileStat;
    int ret = stat(dir_name, &fileStat);

    if (ret == 0)
    {
        return S_ISDIR(fileStat.st_mode);
    }

    return false;
#endif
}

static inline bool DMCreateDirectory(const char *dir_name)
{
#ifdef _WIN32
    int ret = mkdir(dir_name);
#else
    int ret = mkdir(dir_name, S_IRWXU | S_IRWXG | S_IXOTH);
#endif

    if (0 != ret)
    {
        return false;
    }

    return true;
}

static inline bool DMCreateDirectories(const char *dir_name)
{
    if (access(dir_name, 0) == 0)
    {
        if (DMIsDirectory(dir_name))
        {
            return true;
        }

        return false;
    }

    char path[MAX_PATH];
    strncpy(path, dir_name, sizeof(path));

    char *p = strrchr(path, PATH_DELIMITER);

    if (NULL == p)
    {
        return DMCreateDirectory(path);
    }

    *(p) = '\0';
    DMCreateDirectories(path);
    return DMCreateDirectory(dir_name);
}

static inline std::string DMGetRootPath()
{

#ifdef _WIN32
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        GetModuleFileNameA( 0, path, sizeof( path ) );
        char* p = strrchr( path, '\\' );
        if(p)
        {
            *( p ) = '\0';
        }
    });

    return path;
#elif __APPLE__
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        uint32_t size = sizeof( path );
        int nRet = _NSGetExecutablePath( path, &size );

        if ( nRet != 0 ) {
            strcpy(path, "./");
            return;
        }

        char* p = strrchr( path, '/' );
        if(p)
        {
            *( p ) = '\0';
        }
    });
    return path;
#else
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        int nRet = readlink( "/proc/self/exe", path, MAX_PATH );

        if ( nRet < 0 || nRet >= MAX_PATH ) {
            strcpy(path, "./");
            return;
        }

        char* p = strrchr( path, '/' );
        if(p)
        {
            *( p ) = '\0';
        }
     });

    return path;
#endif
}

static inline std::string DMGetExePath()
{
#ifdef _WIN32
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    { 
        GetModuleFileNameA(0, path, sizeof(path));
    });

    return path;
#elif __APPLE__
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        uint32_t size = sizeof( path );
        int nRet = _NSGetExecutablePath( path, &size );

        if ( nRet != 0 )
        {
            strcpy(path, "./");
            return;
        }
    });
    return path;
#else
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        int nRet = readlink( "/proc/self/exe", path, MAX_PATH );

        if ( nRet < 0 || nRet >= MAX_PATH )
        {
            strcpy(path, "./");
            return;
        }
    });

    return path;
#endif
}

static inline std::string DMGetExeName()
{
#ifdef _WIN32
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        char temp[MAX_PATH];
        GetModuleFileNameA(0, temp, sizeof(path));

        char* point = strrchr(temp, '.');

        if (NULL == point) {
            strcpy(path, temp);
            return;
        }

        *point = '\0';

        char* del = strrchr(temp, PATH_DELIMITER);

        if (NULL == del) {
            strcpy(path, temp);
            return;
        }

        strcpy(path, del + 1);
    });

    return path;
#elif __APPLE__
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        char temp[MAX_PATH];
        uint32_t size = sizeof(temp);
        int ret = _NSGetExecutablePath(temp, &size);

        if (ret != 0) {
            strcpy(path, temp);
            return;
        }

        char* point = strrchr(temp, '.');

        if (NULL == point) {
            strcpy(path, temp);
            return;
        }

        *point = '\0';

        char* del = strrchr(temp, PATH_DELIMITER);

        if (NULL == del) {
            strcpy(path, temp);
            return;
        }

        strcpy(path, del + 1);
    });
    return path;
#else
    static char path[MAX_PATH];
    static std::once_flag init_flag;
    std::call_once(init_flag, []()
    {
        char temp[MAX_PATH];
        int ret = readlink("/proc/self/exe", temp, MAX_PATH);

        if (ret < 0 || ret >= MAX_PATH) {
            strcpy(path, temp);
            return;
        }
        temp[ret] = '\0';
        char* del = strrchr(temp, PATH_DELIMITER);

        if (NULL == del) {
            strcpy(path, temp);
            return;
        }

        strcpy(path, del + 1);
    });

    return path;
#endif
}

static inline std::string DMGetExeNameString()
{
    return DMGetExeName();
}

static inline std::string DMGetWorkPath()
{
    char szPath[MAX_PATH];
    getcwd(szPath, sizeof(szPath));
    return szPath;
}

static inline bool DMSetWorkPath(std::string &strPath)
{
    if (0 != chdir(strPath.c_str()))
    {
        return false;
    }
    return true;
}

static inline bool DMSetWorkPath()
{
    std::string strPath = DMGetRootPath() + "\\..\\";
    return DMSetWorkPath(strPath);
}

// tolua_end

#endif // __DMUTIL_H_INCLUDE__
