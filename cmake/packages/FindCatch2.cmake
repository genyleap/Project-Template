#Package Info.
set(CATCH2_NAME "Catch2")
set(CATCH2_DESCRIPTION "A modern, C++-native, test framework for unit-tests, TDD and BDD - using C++14, C++17 and later (C++11 support is in v2.x branch, and C++03 on the Catch1.x branch).")

#Pakcage option.
option(USE_CATCH2 ${CATCH2_DESCRIPTION} FALSE)
if (USE_CATCH2)
    add_definitions(-DUSE_CATCH2)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(Catch2 catch2)
#Package data repository.
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
    list(APPEND LIB_MODULES Catch2::Carch2)
endif()
if(NOT CATCH2_FOUND)
    return()
endif()

