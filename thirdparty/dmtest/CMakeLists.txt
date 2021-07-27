cmake_minimum_required(VERSION 2.8)

PROJECT(dmtest)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
add_compile_definitions(-fprofile-arcs)
LibImport("dmtest" "src/dmtest")
