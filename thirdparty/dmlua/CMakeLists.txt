cmake_minimum_required(VERSION 3.2)

PROJECT(dmlua)

INCLUDE(cmake/ModuleImport.cmake)
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/LuaModule.cmake)
ModuleSetCompileOptions()

SET(LUA_MODULE lua54)

ADD_DEFINITIONS(-DLUA_COMPAT_MODULE -DLUA_COMPAT_APIINTCASTS)
  
SET (CMAKE_C_STANDARD 89)

ShowEnvironment()

LuaModuleImport("${LUA_MODULE}" "libtolua" "src/libtolua" "")

ExeImport("tool" "${LUA_MODULE};libtolua")
ExeImport("samples" "${LUA_MODULE};libtolua")

IF (WIN32)

ADD_CUSTOM_COMMAND(
    TARGET dmluademo
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${LUA_MODULE}> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:libtolua> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:toluapp> ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script

)

ADD_CUSTOM_COMMAND(
    TARGET dmluademo
    PRE_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script/toluapp.exe -t -n interface -o interface.cpp -H interface.h interface.pkg
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script/interface.pkg
    )

ADD_CUSTOM_COMMAND(
    TARGET dmluademo
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/config/lua_dkm_debug.json
    $<TARGET_FILE_DIR:dmluademo>
)

ENDIF(WIN32)
