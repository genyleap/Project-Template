# Package Info.
set(JSON_NAME "JSon")

if(USE_BOOST)
    set(JSON_DESCRIPTION "A C++11 or library for parsing and serializing JSON to and from a DOM container in memory based on Boost.")
else()
    set(JSON_DESCRIPTION "A C++ library for interacting with JSON.")
endif()

# Pakcage option.
option(USE_JSON ${JSON_DESCRIPTION} FALSE)
if (USE_JSON)
    add_definitions(-DUSE_JSON)
    # Define the repository URL and tag for the Boost libraries
    set(JSON_URL "https://github.com/open-source-parsers/jsoncpp.git")
if(FORCE_UPGRADED_LIBS)
    set(JSON_TAG "master")
else()
    set(JSON_TAG "1.9.5")
endif()
    set(JSON_LIB_LIST "jsoncpp_lib" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${JSON_NAME} json)
# Package data repository.

if(USE_JSON)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(json_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${JSON_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${json_base})
    FetchContent_Declare(
        json
        GIT_REPOSITORY      ${JSON_URL}
        GIT_TAG             ${JSON_TAG}
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(json)
    string(TOLOWER "${JSON_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(json)
    include_directories(${${lcName}_INCLUDE_DIR})
    foreach(module IN LISTS JSON_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT JSON_FOUND)
    return()
endif()
