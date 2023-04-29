# Package Info.
set(CURL_NAME "Curl")
set(CURL_DESCRIPTION "A command-line tool used to transfer data from or to a server using various protocols such as HTTP, FTP, SMTP, etc. It is widely used in the development of web applications to test APIs or interact with web servers.")

# Pakcage option.
option(USE_CURL ${CURL_DESCRIPTION} FALSE)
if (USE_CURL)
    add_definitions(-DUSE_CURL)
endif()

if(USE_CURL)
    # Search Curl
    find_package(PkgConfig REQUIRED)
    pkg_search_module(OPENSSL REQUIRED openssl)

    if(CURL_FOUND)
        message(STATUS "Using Curl ${CURL_VERSION}")
    else()
        # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
    endif()
    list(APPEND LIB_MODULES curl)
    list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${CURL_INCLUDE_DIRS})
    list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${CURL_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_LINK_DIRECTORIES ${CURL_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_COMPILER_DEFINATION "")
endif()
if(NOT CURL_FOUND)
    return()
endif()
