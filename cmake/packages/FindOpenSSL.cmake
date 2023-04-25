# Package Info.
set(OPENSSL_NAME "OpenSSL")
set(OPENSSL_DESCRIPTION "TLS/SSL and crypto library.")

# Pakcage option.
option(USE_OPENSSL ${OPENSSL_DESCRIPTION} FALSE)
if (USE_OPENSSL)
    add_definitions(-DUSE_OPENSSL)
    # Define the repository URL and tag for the OpenSSL libraries
    set(OPENSSL_URL "https://github.com/openssl/openssl.git")
if(FORCE_UPGRADED_LIBS)
    set(OPENSSL_TAG "master")
else()
    set(OPENSSL_TAG "openssl-3.1.0")
endif()
    set(OPENSSL_LIB_LIST "OpenSSL::SSL OpenSSL::Crypto" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${OPENSSL_NAME} OpenSSL)
# Package data repository.
if(USE_OPENSSL)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(openssl_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${OPENSSL_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${openssl_base})
    FetchContent_Declare(
        OpenSSL
        GIT_REPOSITORY      ${OPENSSL_URL}
        GIT_TAG             ${OPENSSL_TAG}
        GIT_PROGRESS        TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(OpenSSL)
    string(TOLOWER "${OPENSSL_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
    endif()
    foreach(module IN LISTS OPENSSL_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
    FetchContent_MakeAvailable(OpenSSL)
    list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIRS})
    list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${OPENSSL_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_LINK_DIRECTORIES ${OPENSSL_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_COMPILER_DEFINATION "")
endif()
if(NOT OPENSSL_FOUND)
    return()
endif()
