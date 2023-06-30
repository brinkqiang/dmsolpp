cmake_minimum_required(VERSION 3.2)

PROJECT(dmlua)

INCLUDE(cmake/ModuleImport.cmake)
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/LuaModule.cmake)
ModuleSetCompileOptions()

SET(LUA_MODULE lua54)

ADD_DEFINITIONS(-DLUA_COMPAT_MODULE -DLUA_COMPAT_APIINTCASTS)

LuaModuleImport("${LUA_MODULE}" "libtolua" "src/libtolua" "")

IF (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    ExeImport("tool" "${LUA_MODULE};libtolua")
    ExeImport("samples" "${LUA_MODULE};libtolua")

    IF (WIN32)
    ADD_CUSTOM_COMMAND(
        TARGET dmluademo
        PRE_BUILD
        COMMAND tolua++ -t -n interface -o interface.cpp -H interface.h interface.pkg
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/samples/dmluademo/script
        DEPENDS tolua++
        )

    ADD_CUSTOM_COMMAND(
        TARGET dmluademo
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/config/lua_dkm_debug.json
        $<TARGET_FILE_DIR:dmluademo>
    )
    ENDIF(WIN32)
ENDIF()



