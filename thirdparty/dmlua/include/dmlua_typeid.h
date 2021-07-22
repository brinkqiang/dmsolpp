
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

#ifndef __DMLUA_TYPEID_H_INCLUDE__
#define __DMLUA_TYPEID_H_INCLUDE__

#ifdef __cplusplus

#include <string>
#include <map>
#include <typeinfo>

//#define Mtolua_typeid(L,TI,T) tolua_typeid_reg<TI>(L,T)

struct SLuaTypeInfo
{
    SLuaTypeInfo()
        : m_bInit( false )
    {
    }
    std::string m_strName;
    bool        m_bInit;
};

class CluaTypeid
{
public:
    static CluaTypeid& Instance()
    {
        static CluaTypeid s;
        return s;
    }

    template<typename T>
    inline void type_reg( const char* name )
    {
        name_holder<T>().m_strName = name;
        name_holder<T>().m_bInit = true;
    }

    template<typename T>
    inline const char* get_name()
    {
        return name_holder<T>().m_bInit ? name_holder<T>().m_strName.c_str() : NULL;
    }

private:
    template<typename T>
    inline SLuaTypeInfo& name_holder()
    {
        static SLuaTypeInfo sInfo;
        return sInfo;
    }
};

template<typename T>
inline void Mtolua_typeid( lua_State* tolua_S, const char* name )
{
    CluaTypeid::Instance().type_reg<T>( name );
}
#endif

#endif // __DMLUA_TYPEID_H_INCLUDE__
