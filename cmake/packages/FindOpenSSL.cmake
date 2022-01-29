#Package Info.
set(OPENSSL_NAME "OpenSSL")
set(OPENSSL_DESCRIPTION "TLS/SSL and crypto library.")

#Pakcage option.
option(USE_OPENSSL ${OPENSSL_DESCRIPTION}  FALSE)
if (USE_OPENSSL)
    add_definitions(-DUSE_OPENSSL)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${OPENSSL_NAME} openssl)
#Package data repository.
if(USE_OPENSSL)
    EXTERNALPROJECT_ADD(
        openssl
        PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${OPENSSL_NAME}
        GIT_REPOSITORY "https://github.com/openssl/openssl.git"
        GIT_TAG master
        URL ${CMAKE_SOURCE_DIR}/vendor/openssl-1.1.1i.tar.gz
        CONFIGURE_COMMAND ./config no-idea no-mdc2 no-rc5 --prefix=${CMAKE_BINARY_DIR}
        BUILD_COMMAND make -j${CONCURRENCY}
        INSTALL_COMMAND make install_sw
        BUILD_IN_SOURCE 1
        TIMEOUT 10
        INACTIVITY_TIMEOUT ON
        GIT_PROGRESS ON
        DOWNLOAD_NO_PROGRESS OFF
        LOG_DOWNLOAD ON
        LOG_BUILD ON
        USES_TERMINAL_DOWNLOAD ON
        )
    list(APPEND LIB_MODULES crypto ssl)
endif()
if(NOT OPENSSL_FOUND)
    return()
endif()
