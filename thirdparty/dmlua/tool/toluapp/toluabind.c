/*
** Lua binding: tolua
** Generated automatically by tolua++-1.0.92 on Sun Feb 15 22:29:47 2009.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "luabin.h"

/* Exported function */
TOLUA_API int  tolua_tolua_open( lua_State* tolua_S );


/* function to register type */
static void tolua_reg_types( lua_State* tolua_S ) {
}

/* Open function */
TOLUA_API int tolua_tolua_open( lua_State* tolua_S ) {
    tolua_open( tolua_S );
    tolua_reg_types( tolua_S );
    tolua_module( tolua_S, NULL, 0 );
    tolua_beginmodule( tolua_S, NULL );
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )compat51_data, sizeof( compat51_data ),
                        "tolua embedded: src/bin/lua/compat51.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )compat_data, sizeof( compat_data ),
                        "tolua embedded: src/bin/lua/compat.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )basic_data, sizeof( basic_data ),
                        "tolua embedded: src/bin/lua/basic.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )feature_data, sizeof( feature_data ),
                        "tolua embedded: src/bin/lua/feature.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )verbatim_data, sizeof( verbatim_data ),
                        "tolua embedded: src/bin/lua/verbatim.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )code_data, sizeof( code_data ),
                        "tolua embedded: src/bin/lua/code.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )typedef_data, sizeof( typedef_data ),
                        "tolua embedded: src/bin/lua/typedef.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )container_data, sizeof( container_data ),
                        "tolua embedded: src/bin/lua/container.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )package_data, sizeof( package_data ),
                        "tolua embedded: src/bin/lua/package.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )module_data, sizeof( module_data ),
                        "tolua embedded: src/bin/lua/module.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )namespace_data, sizeof( namespace_data ),
                        "tolua embedded: src/bin/lua/namespace.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )define_data, sizeof( define_data ),
                        "tolua embedded: src/bin/lua/define.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )enumerate_data, sizeof( enumerate_data ),
                        "tolua embedded: src/bin/lua/enumerate.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )declaration_data, sizeof( declaration_data ),
                        "tolua embedded: src/bin/lua/declaration.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )variable_data, sizeof( variable_data ),
                        "tolua embedded: src/bin/lua/variable.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )array_data, sizeof( array_data ),
                        "tolua embedded: src/bin/lua/array.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )function_data, sizeof( function_data ),
                        "tolua embedded: src/bin/lua/function.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )operator_data, sizeof( operator_data ),
                        "tolua embedded: src/bin/lua/operator.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )template_class_data,
                        sizeof( template_class_data ),
                        "tolua embedded: src/bin/lua/template_class.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )class_data, sizeof( class_data ),
                        "tolua embedded: src/bin/lua/class.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )clean_data, sizeof( clean_data ),
                        "tolua embedded: src/bin/lua/clean.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        tolua_dobuffer( tolua_S, ( char* )doit_data, sizeof( doit_data ),
                        "tolua embedded: src/bin/lua/doit.lua" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    {
        /* begin embedded lua code */
        int top = lua_gettop( tolua_S );
        static unsigned char B[] = {
            10, 108, 111, 99, 97, 108, 32, 101, 114, 114, 44, 109, 115, 103, 32,
            61, 32, 112, 99, 97, 108, 108, 40, 100, 111, 105, 116, 41, 10, 105,
            102, 32, 110, 111, 116, 32, 101, 114, 114, 32, 116, 104, 101, 110, 10,
            32, 108, 111, 99, 97, 108, 32, 95, 44, 95, 44, 108, 97, 98, 101,
            108, 44, 109, 115, 103, 32, 61, 32, 115, 116, 114, 102, 105, 110, 100,
            40, 109, 115, 103, 44, 34, 40, 46, 45, 58, 46, 45, 58, 37, 115,
            42, 41, 40, 46, 42, 41, 34, 41, 10, 32, 116, 111, 108, 117, 97,
            95, 101, 114, 114, 111, 114, 40, 109, 115, 103, 44, 108, 97, 98, 101,
            108, 41, 10, 32, 112, 114, 105, 110, 116, 40, 100, 101, 98, 117, 103,
            46, 116, 114, 97, 99, 101, 98, 97, 99, 107, 40, 41, 41, 10, 101,
            110, 100, 32
        };
        tolua_dobuffer( tolua_S, ( char* )B, sizeof( B ),
                        "tolua: embedded Lua code 23" );
        lua_settop( tolua_S, top );
    } /* end of embedded lua code */
    tolua_endmodule( tolua_S );
    return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
TOLUA_API int luaopen_tolua( lua_State* tolua_S ) {
    return tolua_tolua_open( tolua_S );
};
#endif

