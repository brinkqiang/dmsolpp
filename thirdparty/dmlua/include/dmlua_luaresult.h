
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

#ifndef __DMLUA_LUARESULT_H_INCLUDE__
#define __DMLUA_LUARESULT_H_INCLUDE__

#include <string>
#include "dmtypes.h"

template<typename T>
struct LuaResult
{
    LuaResult() : value( T() ) {}
    LuaResult( const T& t ) : value( t ) {}
    operator T& ()
    {
        return value;
    }
    T value;
};

template<>
struct LuaResult<std::string>
{
    LuaResult() : value( std::string() ) {}
    operator const char* ()
    {
        return value.c_str();
    }
    std::string value;
};

template<>
struct LuaResult<int64_t>
{
    LuaResult() : value( 0 ) {}
    LuaResult( const int64_t& t ) : value( t ) {}
    operator int64_t()
    {
        return value;
    }
    int64_t value;
};

template<>
struct LuaResult<uint64_t>
{
    LuaResult() : value( 0 ) {}
    LuaResult( const uint64_t& t ) : value( t ) {}
    operator uint64_t()
    {
        return value;
    }
    uint64_t value;
};

typedef LuaResult<int>                  LResultINT;
typedef LuaResult<int64_t>              LResultINT64;
typedef LuaResult<uint64_t>             LResultUINT64;
typedef LuaResult<double>               LResultDOUBLE;

typedef LuaResult<std::string>          LResultSTRING;

#endif // __DMLUA_LUARESULT_H_INCLUDE__
