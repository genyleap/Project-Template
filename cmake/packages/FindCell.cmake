#Package Info.
set(ENGINE_NAME "Cell")
set(ENGINE_DESCRIPTION "Cell Engine is a new and exclusive cross-platform computer application engine based on Modern C++.")

message("Preparing for " ${ENGINE_NAME} "Engine")

find_package(PkgConfig QUIET)
pkg_search_module(${ENGINE_NAME} cell)
#Package data repository.

    set(FETCHCONTENT_QUIET off)
    get_filename_component(cell_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${ENGINE_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${cell_base})
    FetchContent_Declare(
        cell
        GIT_REPOSITORY https://github.com/genyleap/cell.git
        GIT_TAG main
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(cell)
    string(TOLOWER "${ENGINE_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(cell)
    include_directories(${${lcName}_INCLUDE_DIR})
    list(APPEND LIB_MODULES cell_lib)

if(NOT CELL_FOUND)
    return()
endif()
