#Package Info.
set(BOOST_NAME "Boost")
set(BOOST_DESCRIPTION "The Boost project provides free peer-reviewed portable C++ source libraries.")

#Pakcage option.
option(USE_BOOST ${BOOST_DESCRIPTION} FALSE)
if (USE_BOOST)
    add_definitions(-DUSE_BOOST)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(Boost boost)
#Package data repository.
if(USE_BOOST)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(boost_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${BOOST_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${boost_base})
    FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG master
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
    list(APPEND LIB_MODULES ${Boost_LIBRARIES})
endif()
if(NOT BOOST_FOUND)
    return()
endif()
