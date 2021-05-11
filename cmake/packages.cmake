cmake_minimum_required(VERSION 3.20)
if(${CMAKE_VERSION} VERSION_LESS 3.20)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.20)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

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

option(USE_CURL    "Include Curl"  FALSE)
if (USE_CURL)
  add_definitions(-DUSE_CURL)
endif()

option(USE_GOOGLE_TEST    "Include Google-Test"  FALSE)
if (USE_GOOGLE_TEST)
  add_definitions(-DUSE_GOOGLE_TEST)
endif()

option(USE_DOC_TEST    "Include DocTest"  FALSE)
if (USE_DOC_TEST)
  add_definitions(-DUSE_DOC_TEST)
endif()

option(USE_CATCH2    "Include Catch2"  TRUE)
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

if(USE_DOC_TEST)

set(FETCHCONTENT_QUIET off)

get_filename_component(doctest_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/doctest"
                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
set(FETCHCONTENT_BASE_DIR ${doctest_base})
FetchContent_Declare(
  DocTest
  GIT_REPOSITORY      https://github.com/onqtam/doctest
  GIT_TAG master
  GIT_PROGRESS   TRUE
  USES_TERMINAL_DOWNLOAD TRUE
)

# Check if population has already been performed
FetchContent_GetProperties(doctest)
string(TOLOWER "doctest" lcName)
if(NOT ${lcName}_POPULATED)
FetchContent_Populate(${lcName})
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
FetchContent_MakeAvailable(DocTest)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest)
endif()

if(USE_CURL)

set(FETCHCONTENT_QUIET off)

get_filename_component(curl_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/curl"
                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
set(FETCHCONTENT_BASE_DIR ${curl_base})
FetchContent_Declare(
  curl
  GIT_REPOSITORY      https://github.com/curl/curl.git
  GIT_TAG master
  GIT_PROGRESS   TRUE
  USES_TERMINAL_DOWNLOAD TRUE
)

# Check if population has already been performed
FetchContent_GetProperties(curl)
string(TOLOWER "curl" lcName)
if(NOT ${lcName}_POPULATED)
FetchContent_Populate(${lcName})
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
FetchContent_MakeAvailable(curl)
endif()


if(USE_GOOGLE_TEST)
set(FETCHCONTENT_QUIET off)
get_filename_component(googletest_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/gtest"
                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
set(FETCHCONTENT_BASE_DIR ${googletest_base})
FetchContent_Declare(
  gtest
  GIT_REPOSITORY      https://github.com/google/googletest.git
  GIT_TAG master
  GIT_PROGRESS   TRUE
  USES_TERMINAL_DOWNLOAD TRUE
)

# Check if population has already been performed
FetchContent_GetProperties(gtest)
string(TOLOWER "gtest" lcName)
if(NOT ${lcName}_POPULATED)
FetchContent_Populate(${lcName})
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
FetchContent_MakeAvailable(gtest)
endif()

if(USE_CATCH2)
set(FETCHCONTENT_QUIET off)
get_filename_component(catch2_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/catch2"
                       REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
set(FETCHCONTENT_BASE_DIR ${catch2_base})
FetchContent_Declare(
  catch2
  GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
  GIT_TAG devel
  GIT_PROGRESS   TRUE
  USES_TERMINAL_DOWNLOAD TRUE
)

# Check if population has already been performed
FetchContent_GetProperties(catch2)
string(TOLOWER "catch2" lcName)
if(NOT ${lcName}_POPULATED)
FetchContent_Populate(${lcName})
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
FetchContent_MakeAvailable(catch2)
endif()

if(USE_NONE_STL_JSON)

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
FetchContent_Populate(${lcName})
add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
FetchContent_MakeAvailable(json)
endif()

if(USE_CPP_CHECK)
externalproject_add(cppcheck
    GIT_REPOSITORY "https://github.com/danmar/cppcheck.git"
    GIT_TAG main
    INSTALL_DIR "${CMAKE_BINARY_DIR}/install/cppcheck"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/cppcheck
    CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/cppcheck
    UPDATE_COMMAND ""
    )
endif()
