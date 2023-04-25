# Package Info.
set(GTEST_NAME "GTest")
set(GTEST_DESCRIPTION "GoogleTest - Google Testing and Mocking Framework.")

# Pakcage option.
option(USE_GOOGLE_TEST ${GTEST_DESCRIPTION} FALSE)
if (USE_GOOGLE_TEST)
    add_definitions(-DUSE_GOOGLE_TEST)
    # Define the repository URL and tag for the Boost libraries
    set(GTEST_URL "https://github.com/google/googletest.git")
if(FORCE_UPGRADED_LIBS)
    set(GTEST_TAG "master")
else()
    set(GTEST_TAG "v1.13.0")
endif()
    set(GTEST_LIB_LIST "gtest" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(GTest gtest)
# Package data repository.
if(USE_GOOGLE_TEST)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(gtest_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/gtest"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${gtest_base})
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY      ${GTEST_URL}
        GIT_TAG             ${GTEST_TAG}
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
    foreach(module IN LISTS GTEST_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT GTEST_FOUND)
    return()
endif()
