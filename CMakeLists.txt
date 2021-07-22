cmake_minimum_required(VERSION 3.2)

PROJECT(dmsolpp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMSOLPP_VERSION_MAJOR "1")
SET(DMSOLPP_VERSION_MINOR "0")
SET(DMSOLPP_VERSION_PATCH "1")
SET(DMSOLPP_VERSION "${DMSOLPP_VERSION_MAJOR}.${DMSOLPP_VERSION_MINOR}.${DMSOLPP_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSOLPP_VERSION}")

OPTION(USE_DMSOLPP "use dmsolpp" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmsolpp_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmsolpp_config.h)

LibImport("dmsolpp_module" "src/dmsolpp_module")
ExeImport("test" "dmsolpp_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmsolpptest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmsolpptest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmsolpp
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMSOLPP_LIBS "dmsolpp")
#MARK_AS_ADVANCED(${DMSOLPP_LIBS})