cmake_minimum_required(VERSION 3.5)


# project setup
project(cet-cli CXX)

if(NOT CMAKE_CROSSCOMPILING) # If cross compile is failing, you should set. CMAKE_SYSTEM_NAME in your toolchain file.
    set(BUILD_PROGRAMS ON)
else()
    set(BUILD_PROGRAMS OFF)
endif()

option(BUILD_CTL "build cet-cli" ${BUILD_PROGRAMS})

set(CETCLI_MAJOR_VERSION 0)
set(CETCLI_MINOR_VERSION 0)
set(CETCLI_PATCH_VERSION 0)
set(CETCLI_VERSION
    ${CETCLI_MAJOR_VERSION}.${CETCLI_MINOR_VERSION}.${CETCLI_PATCH_VERSION})
set(CETCLI_VERSION_STRING "${CETCLI_VERSION}")

set(CMAKE_GENERATOR Ninja) # may the build behaviour not confuse you


include(CheckIncludeFileCXX)

if (${CMAKE_CXX_STANDARD} 20)
    set(CXX_STANDARD 20)
elseif(${CMAKE_CXX_STANDARD} 17)
    set(CXX_STANDARD 17)
else()
    set(CXX_STANDARD 14)
endif()


# option build
if(BUILD_CTL)
    add_subdirectory(cet-cli)
    set(BUILD_CET-CLI_ON "ON")
else()
    set(BUILD_CET-CLI_ON "OFF")
endif()


# messaage
message(STATUS "project         : " ${PROJECT_NAME})
message(STATUS "version         : " ${CETCLI_VERSION_STRING})
message(STATUS "compiler        : " ${CMAKE_CXX_COMPILER_ID})
message(STATUS "generator       : " ${CMAKE_GENERATOR})
message(STATUS "cxx standard    : " ${CXX_STANDARD})
# 
message(STATUS "build get-cli   : " ${BUILD_GETCLI})
