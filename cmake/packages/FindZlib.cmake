#Package Info.
set(ZLIB_NAME "Zlib")
set(ZLIB_DESCRIPTION "A massively spiffy yet delicately unobtrusive compression library.")

#Pakcage option.
option(USE_ZLIB ${ZLIB_DESCRIPTION} FALSE)
if (USE_ZLIB)
    add_definitions(-DUSE_ZLIB)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${ZLIB_NAME} zlib)
#Package data repository.
if(USE_ZLIB)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(ctre_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${ZLIB_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${ctre_base})
    FetchContent_Declare(
        zlib
        GIT_REPOSITORY     https://github.com/madler/zlib.git
        GIT_TAG master
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(zlib)
    string(TOLOWER "${ZLIB_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(zlib)
    list(APPEND LIB_MODULES zlib)
    list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${ZLIB_INCLUDE_DIRS})
    list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${ZLIB_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_LINK_DIRECTORIES ${ZLIB_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_COMPILER_DEFINATION "")
    list(APPEND LIB_TARGET_PROPERTIES "-D_FILE_OFFSET_BITS=64")
endif()
if(NOT ZLIB_FOUND)
    return()
endif()
