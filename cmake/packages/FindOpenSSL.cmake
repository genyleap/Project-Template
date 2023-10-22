# Package Info.
set(OPENSSL_NAME "OpenSSL")
set(OPENSSL_DESCRIPTION "TLS/SSL and crypto library.")

# Pakcage option.
option(USE_OPENSSL ${OPENSSL_DESCRIPTION} FALSE)
if (USE_OPENSSL)
    add_definitions(-DUSE_OPENSSL)
endif()

set(OPENSSL_WASM_PATH_INCLUDE "")
set(OPENSSL_WASM_PATH_LIB "")

if (USE_OPENSSL)
    add_definitions(-DUSE_OPENSSL)
endif()

# Package data repository.
if(USE_OPENSSL)
    # Search OpenSSL
    if(EMSCRIPTEN)
        message("Using emscripten!")
        message("Set custom emscripten lib!")
        list(APPEND LIB_MODULES ssl crypto)
        list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${OPENSSL_WASM_PATH_INCLUDE})
        list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${OPENSSL_WASM_PATH_LIB})
        list(APPEND LIB_TARGET_LINK_DIRECTORIES ${OPENSSL_WASM_PATH_LIB})
        list(APPEND LIB_TARGET_COMPILER_DEFINATION "")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1 -s USE_ZLIB=1")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1 -s USE_ZLIB=1")
    else()
        find_package(PkgConfig REQUIRED)
        pkg_search_module(OPENSSL REQUIRED openssl)
        if( OPENSSL_FOUND )
            message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
        else()
            # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
        endif()
        list(APPEND LIB_MODULES ssl crypto)
        list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIRS})
        list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${OPENSSL_LIBRARY_DIRS})
        list(APPEND LIB_TARGET_LINK_DIRECTORIES ${OPENSSL_LIBRARY_DIRS})
        list(APPEND LIB_TARGET_COMPILER_DEFINATION "")
    endif()

endif()
if(NOT OPENSSL_FOUND)
    message("Please install OpenSSL from system root first! Use [https://www.openssl.org/source/]")
    return()
endif()
