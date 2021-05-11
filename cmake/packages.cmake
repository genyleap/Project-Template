cmake_minimum_required(VERSION 3.20)
if(${CMAKE_VERSION} VERSION_LESS 3.20)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.20)
endif()

include(ExternalProject)
include(FetchContent)

option(USE_LATEST_STANDARD    "Include latest standard of C++"  TRUE)
if (USE_LATEST_STANDARD)
  add_definitions(-DUSE_LATEST_STANDARD)
endif()

option(USE_BOOST    "Include Boost library"  FALSE)
if (USE_BOOST)
  add_definitions(-DUSE_BOOST)
endif()

option(USE_CPP_CHECK    "Include CppCheck library"  FALSE)
if (USE_CPP_CHECK)
  add_definitions(-DUSE_CPP_CHECK)
endif()

option(USE_GOOGLE_TEST    "Include Google-Test"  FALSE)
if (USE_GOOGLE_TEST)
  add_definitions(-DUSE_GOOGLE_TEST)
endif()

option(USE_CATCH2    "Include Catch2"  FALSE)
if (USE_CATCH2)
  add_definitions(-DUSE_CATCH2)
endif()

option(USE_NONE_STL_JSON    "Include JSON"  TRUE)
if (USE_NONE_STL_JSON)
  add_definitions(-DUSE_NONE_STL_JSON)
endif()

option(USE_OPENSSL    "Include OpenSSL"  FALSE)
if (USE_OPENSSL)
  add_definitions(-DUSE_OPENSSL)
endif()

option(USE_ZLIB    "Include Zlib"  FALSE)
if (USE_ZLIB)
  add_definitions(-DUSE_ZLIB)
endif()


message(STATUS "CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}")

set(LIB_SOURCE_DIR "lib")
set(TEMP_SOURCE_DIR "temp")
set(THIRD_PARTY "third-party")

include(FindGit)
find_package(Git)
if (NOT Git_FOUND)
    message(FATAL_ERROR "Git not found!")
endif ()

if(USE_OPENSSL)
EXTERNALPROJECT_ADD(
  openssl
  PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/openssl
  GIT_REPOSITORY "https://github.com/openssl/openssl.git"
  GIT_TAG master
  URL ${CMAKE_SOURCE_DIR}/vendor/openssl-1.1.1i.tar.gz
  CONFIGURE_COMMAND ./config no-idea no-mdc2 no-rc5 --prefix=${CMAKE_BINARY_DIR}
  BUILD_COMMAND make -j${CONCURRENCY}
  INSTALL_COMMAND make install_sw
  BUILD_IN_SOURCE 1
  TIMEOUT 10
  INACTIVITY_TIMEOUT ON
  GIT_PROGRESS ON
  DOWNLOAD_NO_PROGRESS OFF
  LOG_DOWNLOAD ON
  LOG_BUILD ON
  USES_TERMINAL_DOWNLOAD ON
)
endif()

if(USE_ZLIB)
externalproject_add(
    zlib
    GIT_REPOSITORY "https://github.com/madler/zlib.git"
    GIT_TAG master
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    TIMEOUT 10

    INSTALL_DIR "${CMAKE_BINARY_DIR}/install"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/zlib
    CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/install/zlib

    DOWNLOAD_DIR ${TEMP_SOURCE_DIR}/zlib/downloads
    SOURCE_DIR ${TEMP_SOURCE_DIR}/zlib/src
    BINARY_DIR ${TEMP_SOURCE_DIR}/zlib/build
    STAMP_DIR  ${TEMP_SOURCE_DIR}/zlib/stamp

    BUILD_IN_SOURCE OFF
    INACTIVITY_TIMEOUT ON
    GIT_PROGRESS ON
    DOWNLOAD_NO_PROGRESS OFF
    LOG_DOWNLOAD ON
    LOG_UPDATE ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_TEST ON
    USES_TERMINAL_DOWNLOAD ON
    USES_TERMINAL_UPDATE ON
    USES_TERMINAL_BUILD ON
    USES_TERMINAL_TEST ON
    USES_TERMINAL_INSTALL ON
    LOG ON
)
endif()

if(USE_GOOGLE_TEST)
externalproject_add(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG master
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    TIMEOUT 10

    INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/googletest"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/googletest
    CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/googletest

    DOWNLOAD_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/googletest/downloads
    SOURCE_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/googletest/src
    BINARY_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/googletest/build
    STAMP_DIR  ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/googletest/stamp

    BUILD_IN_SOURCE OFF
    INACTIVITY_TIMEOUT ON
    GIT_PROGRESS ON
    DOWNLOAD_NO_PROGRESS OFF
    LOG_DOWNLOAD ON
    LOG_UPDATE ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_TEST ON
    USES_TERMINAL_DOWNLOAD ON
    USES_TERMINAL_UPDATE ON
    USES_TERMINAL_BUILD ON
    USES_TERMINAL_TEST ON
    USES_TERMINAL_INSTALL ON
    LOG ON
)
endif()
#if(USE_CATCH2)
#externalproject_add(
#    catch2
#    GIT_REPOSITORY "https://github.com/catchorg/Catch2.git"
#    GIT_TAG devel
#    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
#    TIMEOUT 10

#    INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2"
#    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2
#    CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2

#    DOWNLOAD_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/catch2/downloads
#    SOURCE_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/catch2/src
#    BINARY_DIR ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/catch2/build
#    STAMP_DIR  ${TEMP_SOURCE_DIR}/${THIRD_PARTY}/catch2/stamp

#    BUILD_IN_SOURCE OFF
#    INACTIVITY_TIMEOUT ON
#    GIT_PROGRESS ON
#    DOWNLOAD_NO_PROGRESS OFF
#    LOG_DOWNLOAD ON
#    LOG_UPDATE ON
#    LOG_CONFIGURE ON
#    LOG_BUILD ON
#    LOG_TEST ON
#    USES_TERMINAL_DOWNLOAD ON
#    USES_TERMINAL_UPDATE ON
#    USES_TERMINAL_BUILD ON
#    USES_TERMINAL_TEST ON
#    USES_TERMINAL_INSTALL ON
#    LOG ON
#)
#ExternalProject_Get_Property(catch2 SOURCE_DIR)
#set(CATCH2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2/include CACHE INTERNAL "Path to include folder for Catch2")
#set(CATCH2_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2/lib CACHE INTERNAL "Path to lib folder for Catch2")
#endif()

if(USE_NONE_STL_JSON)
include(FetchContent)
set(FETCHCONTENT_QUIET off)

get_filename_component(json_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/json"
                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
set(FETCHCONTENT_BASE_DIR ${json_base})

FetchContent_Declare(
  json
  GIT_REPOSITORY      https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG master
  GIT_PROGRESS   TRUE
)

# Check if population has already been performed
FetchContent_GetProperties(json)
string(TOLOWER "json" lcName)
if(NOT ${lcName}_POPULATED)
FetchContent_Populate(json)
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
endif()

FetchContent_MakeAvailable(json)

if(USE_CPP_CHECK)
#include(FetchContent)
#set(FETCHCONTENT_QUIET off)

#get_filename_component(cppcheck_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/cppcheck"
#                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
#set(FETCHCONTENT_BASE_DIR ${cppcheck_base})

#FetchContent_Declare(
#  cppcheck
#  GIT_REPOSITORY      https://github.com/danmar/cppcheck.git
#  GIT_TAG main
#  GIT_PROGRESS   TRUE
#)

## Check if population has already been performed
#FetchContent_GetProperties(cppcheck)
#string(TOLOWER "cppcheck" lcName)
#if(NOT ${lcName}_POPULATED)
#FetchContent_Populate(cppcheck)
#add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
#endif()

#FetchContent_MakeAvailable(cppcheck)

externalproject_add(cppcheck
    GIT_REPOSITORY "https://github.com/danmar/cppcheck.git"
    GIT_TAG main
    INSTALL_DIR "${CMAKE_BINARY_DIR}/install/cppcheck"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/cppcheck
    CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/cppcheck
    UPDATE_COMMAND ""
    )
endif()



if(USE_BOOST)
find_package(Boost REQUIRED)
if(Boost_FOUND)
message(STATUS "Boost version: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIRS})
endif()
# ------ BOOST ------
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs.
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and.
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs.
set(Boost_USE_MULTITHREADED      ON)  # use multithread mode.
set(Boost_USE_STATIC_RUNTIME    OFF)  # use static mode at runtime.
set(LibraryList ${Boost_LIBRARIES})
endif()
