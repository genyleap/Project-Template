#Package Info.
set(DOCTEST_NAME "DocTest")
set(DOCTEST_DESCRIPTION "The fastest feature-rich C++11/14/17/20 single-header testing framework.")

#Pakcage option.
option(USE_DOC_TEST ${DOCTEST_DESCRIPTION} FALSE)
if (USE_DOC_TEST)
    add_definitions(-DUSE_DOC_TEST)
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
    list(APPEND LIB_MODULES doctest)
endif()
if(NOT DOCTEST_FOUND)
    return()
endif()
