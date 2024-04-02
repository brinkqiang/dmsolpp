cmake_minimum_required(VERSION 3.2)

PROJECT(dmsolpp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/LuaModule.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMSOLPP_VERSION_MAJOR "1")
SET(DMSOLPP_VERSION_MINOR "0")
SET(DMSOLPP_VERSION_PATCH "1")
SET(DMSOLPP_VERSION "${DMSOLPP_VERSION_MAJOR}.${DMSOLPP_VERSION_MINOR}.${DMSOLPP_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSOLPP_VERSION}")

OPTION(USE_DMSOLPP "use dmsolpp" OFF)

SET(LUA_MODULE lua54)
ADD_DEFINITIONS(-DLUA_COMPAT_MODULE -DLUA_COMPAT_APIINTCASTS)

ModuleInclude("dmlua" "thirdparty/dmlua/src/${LUA_MODULE}")
ModuleInclude("dmlua" "thirdparty/dmlua/src/libtolua")

ModuleImport("dmtest" "thirdparty/dmtest")
ModuleImport("dmlua" "thirdparty/dmlua")
ModuleImport("dmformat" "thirdparty/dmformat")

LibImport("dmsolpp" "src/dmsolpp")
ExeImport("test" "dmsolpp;dmtest;${LUA_MODULE};libtolua")

IF (WIN32)
#ADD_CUSTOM_COMMAND(
#    TARGET dmsolpptest
#    PRE_BUILD
#    COMMAND dmsolpp --PKG=interface.pkg
#    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test/dmsolpptest
#    DEPENDS dmsolpptest
#    )

ADD_CUSTOM_COMMAND(
    TARGET dmsolpptest
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/config/lua_dkm_debug.json
    $<TARGET_FILE_DIR:dmsolpptest>
)
ENDIF(WIN32)
