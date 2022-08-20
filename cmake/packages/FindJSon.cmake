#Package Info.
set(NONE_STL_JSON_NAME "JSon")
set(NONE_STL_JSON_DESCRIPTION "JSON for Modern C++.")

#Pakcage option.
option(USE_NONE_STL_JSON ${NONE_STL_JSON_DESCRIPTION} FALSE)
if (USE_NONE_STL_JSON)
    add_definitions(-DUSE_NONE_STL_JSON)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${NONE_STL_JSON_NAME} json)
#Package data repository.
if(USE_NONE_STL_JSON)
    set(FETCHCONTENT_QUIET off)

    get_filename_component(json_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${NONE_STL_JSON_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${json_base})

    FetchContent_Declare(
        json
        GIT_REPOSITORY      https://github.com/nlohmann/json.git
        GIT_TAG master
        GIT_PROGRESS   TRUE
        )

    # Check if population has already been performed
    FetchContent_GetProperties(json)
    string(TOLOWER ${NONE_STL_JSON_NAME} lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(json)
    list(APPEND LIB_MODULES nlohmann_json::nlohmann_json)
endif()
if(NOT NONE_STL_JSON_FOUND)
    return()
endif()
