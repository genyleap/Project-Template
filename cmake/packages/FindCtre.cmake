#Package Info.
set(CTRE_NAME "Ctre")
set(CTRE_DESCRIPTION "A Compile time PCRE (almost) compatible regular expression matcher.")

#Pakcage option.
option(USE_CTRE ${CTRE_DESCRIPTION} FALSE)
if (USE_CTRE)
    add_definitions(-DUSE_CTRE)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${DOCTEST_NAME} ctre)
#Package data repository.
if(USE_CTRE_NAME)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(ctre_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${CTRE_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${ctre_base})
    FetchContent_Declare(
        ctre
        GIT_REPOSITORY     https://github.com/hanickadot/compile-time-regular-expressions.git
        GIT_TAG main
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(ctre)
    string(TOLOWER "ctre" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(ctre)
    list(APPEND LIB_MODULES ctre)
endif()
if(NOT CTRE_FOUND)
    return()
endif()
