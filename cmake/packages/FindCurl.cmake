#if(UNIX)
#  find_package(PkgConfig QUIET)
#  pkg_search_module(CURL curl)
#endif()
#if(NOT CURL_FOUND)
#  return()
#endif()

#set(CURL_LIBRARIES ${CURL_LINK_LIBRARIES})
#set(CURL_INCLUDE_DIRS ${CURL_INCLUDE_DIRS})

#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(CURL
#    REQUIRED_VARS CURL_LIBRARIES CURL_INCLUDE_DIRS
#    VERSION_VAR CURL_VERSION)

#mark_as_advanced(CURL_INCLUDE_DIRS CURL_LIBRARIES)

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
