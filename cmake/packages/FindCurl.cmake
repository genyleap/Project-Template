option(USE_CURL    "Include Curl"  FALSE)
if (USE_CURL)
    add_definitions(-DUSE_CURL)
endif()

if(USE_CURL)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(curl_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/curl" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${curl_base})
    FetchContent_Declare(
        curl
        GIT_REPOSITORY      https://github.com/curl/curl.git
        GIT_TAG master
        GIT_PROGRESS   TRUE
        USES_TERMINAL_DOWNLOAD TRUE
        )

    # Check if population has already been performed
    FetchContent_GetProperties(curl)
    string(TOLOWER "curl" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(curl)
endif()
