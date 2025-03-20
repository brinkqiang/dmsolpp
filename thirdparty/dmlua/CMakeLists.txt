cmake_minimum_required(VERSION 3.8)

project(dmlua)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(cmake/ModuleImport.cmake)
include(cmake/ModuleCompileOptions.cmake)
include(cmake/LuaModule.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

set(LUA_MODULE lua54)

add_definitions(-DLUA_COMPAT_MODULE -DLUA_COMPAT_APIINTCASTS)

ShowEnvironment()

LuaModuleImport("${LUA_MODULE}" "libtolua" "src/libtolua" "")

ExeImport("tool" "${LUA_MODULE};libtolua")

if (PROJECT_IS_TOP_LEVEL)
    ExeImport("samples" "${LUA_MODULE};libtolua")

    if (WIN32)
        add_custom_command(
            TARGET dmluademo
            PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${LUA_MODULE}> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:libtolua> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:toluapp> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
        
        )
        
        add_custom_command(
            TARGET dmluademo
            PRE_BUILD
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script/toluapp.exe -t -n interface -o interface.cpp -H interface.h interface.pkg
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
            MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script/interface.pkg
            )
        
        add_custom_command(
            TARGET dmluademo
            PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/config/lua_dkm_debug.json
            $<TARGET_FILE_DIR:dmluademo>
        )
    endif()
endif()
