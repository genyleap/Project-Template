# Package Info.
set(FMT_NAME "Fmt")
set(FMT_DESCRIPTION "A modern formatting library.")

# Pakcage option.
option(USE_FMT ${FMT_DESCRIPTION} FALSE)
if (USE_FMT)
    add_definitions(-DUSE_FMT)
    # Define the repository URL and tag for the Fmt libraries
    set(FMT_URL "https://github.com/fmtlib/fmt.git")
if(FORCE_UPGRADED_LIBS)
    set(FMT_TAG "master")
else()
    set(FMT_TAG "9.1.0")
endif()
    set(FMT_LIB_LIST "fmt::fmt-header-only" CACHE STRING "List of modules (separated by a semicolon)")
endif()

if(USE_FMT)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(fmt_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${FMT_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${fmt_base})
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY      ${FMT_URL}
        GIT_TAG             ${FMT_TAG}
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(fmt)
    string(TOLOWER "${FMT_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(fmt)
    foreach(module IN LISTS FMT_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT FMT_FOUND)
    return()
endif()
