# Package Info.
set(BOOST_NAME "Boost")
set(BOOST_DESCRIPTION "The Boost project provides free peer-reviewed portable C++ source libraries.")
# Pakcage option.
option(USE_BOOST ${BOOST_DESCRIPTION} FALSE)
if (USE_BOOST)
    add_definitions(-DUSE_BOOST)
    # Define the repository URL and tag for the Boost libraries
    set(BOOST_URL "https://github.com/boostorg/boost.git")
if(FORCE_UPGRADED_LIBS)
    set(BOOST_TAG "master")
else()
    set(BOOST_TAG "boost-1.82.0")
endif()
    set(BOOST_LIB_LIST "Boost::system;Boost::chrono;Boost::filesystem;Boost::json" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(Boost boost)
# Package data repository.
if(USE_BOOST)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(boost_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${BOOST_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${boost_base})
    # Declare the Boost libraries with their submodules using FetchContent_Declare
    FetchContent_Declare(
        boost
        GIT_REPOSITORY ${BOOST_URL}
        GIT_TAG ${BOOST_TAG}
        GIT_PROGRESS   TRUE
        USES_TERMINAL_DOWNLOAD TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(boost)
    string(TOLOWER "${BOOST_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(boost)
    foreach(module IN LISTS BOOST_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT BOOST_FOUND)
    return()
endif()
