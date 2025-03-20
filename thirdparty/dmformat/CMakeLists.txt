cmake_minimum_required(VERSION 3.2)

PROJECT(dmformat)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

InterfaceImport("dmformat" "include" "")

if (PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dmformat")
endif()