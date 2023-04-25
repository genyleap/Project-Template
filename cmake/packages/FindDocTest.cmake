#Package Info.
set(DOCTEST_NAME "DocTest")
set(DOCTEST_DESCRIPTION "The fastest feature-rich C++11/14/17/20 single-header testing framework.")

#Pakcage option.
option(USE_DOC_TEST ${DOCTEST_DESCRIPTION} FALSE)
if (USE_DOC_TEST)
    add_definitions(-DUSE_DOC_TEST)
    # Define the repository URL and tag for the DocTest libraries
    set(DOC_TEST_URL "https://github.com/onqtam/doctest")
if(FORCE_UPGRADED_LIBS)
    set(DOC_TEST_TAG "master")
else()
    set(DOC_TEST_TAG "v2.4.11")
endif()
    set(DOC_TEST_LIB_LIST "doctest" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${DOCTEST_NAME} doctest)
#Package data repository.
if(USE_DOC_TEST)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(doctest_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/doctest" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${doctest_base})
    FetchContent_Declare(
        DocTest
        GIT_REPOSITORY      ${DOC_TEST_URL}
        GIT_TAG             ${DOC_TEST_TAG}
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
    foreach(module IN LISTS DOC_TEST_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT DOCTEST_FOUND)
    return()
endif()
