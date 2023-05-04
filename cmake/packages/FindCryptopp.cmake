# Package Info.
set(CRYPTOPP_NAME "Cryptopp")
set(CRYPTOPP_DESCRIPTION "free C++ class library of cryptographic schemes")

# Pakcage option.
option(USE_CRYPTOPP ${CRYPTOPP_DESCRIPTION} FALSE)
if (USE_CRYPTOPP)
    add_definitions(-DUSE_CRYPTOPP)
    # Define the repository URL and tag for the CRYPTOPP libraries
    set(CRYPTOPP_URL "https://github.com/weidai11/cryptopp.git")
if(FORCE_UPGRADED_LIBS)
    set(CRYPTOPP_TAG "master")
else()
    set(CRYPTOPP_TAG "CRYPTOPP_8_7_0")
endif()
    set(CRYPTOPP_LIB_LIST "cryptopp" CACHE STRING "List of modules (separated by a semicolon)")
endif()

if(USE_CRYPTOPP)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(cryptopp_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${CRYPTOPP_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${cryptopp_base})
    FetchContent_Declare(
        cryptopp
        GIT_REPOSITORY      ${CRYPTOPP_URL}
        GIT_TAG             ${CRYPTOPP_TAG}
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(cryptopp)
    string(TOLOWER "${CRYPTOPP_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_library(${lcName} STATIC ${${lcName}_SOURCE_DIR}/cryptlib.cpp)
    endif()
    FetchContent_MakeAvailable(cryptopp)
    include_directories(${${lcName}_SOURCE_DIR})
    foreach(module IN LISTS CRYPTOPP_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT CRYPTOPP_FOUND)
    return()
endif()
