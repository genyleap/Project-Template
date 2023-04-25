# Package Info.
set(OPENMESH_NAME "OpenMesh")
set(OPENMESH_DESCRIPTION "A generic and efficient polygon mesh data structure.")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Pakcage option.
option(USE_OPENMESH ${OPENMESH_DESCRIPTION} FALSE)
if (USE_OPENMESH)
    add_definitions(-DUSE_OPENMESH)
    # Define the repository URL and tag for the OpenMesh libraries
    set(OPENMESH_URL "https://github.com/Lawrencemm/openmesh.git")
if(FORCE_UPGRADED_LIBS)
    set(OPENMESH_TAG "master")
else()
    set(OPENMESH_TAG "lm-minimal")
endif()
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${OPENMESH_NAME} openmesh)
# Package data repository.
if(USE_OPENMESH)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(openmesh_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${OPENMESH_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${openmesh_base})
    FetchContent_Declare(
        openmesh
        GIT_REPOSITORY      ${OPENMESH_URL}
        GIT_TAG             ${OPENMESH_TAG}
        GIT_PROGRESS   TRUE
        USES_TERMINAL_DOWNLOAD TRUE
        )

    # Check if population has already been performed
    FetchContent_GetProperties(openmesh)
    string(TOLOWER "openmesh" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(openmesh)
    list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${OPENMESH_INCLUDE_DIRS})
    list(APPEND LIB_TARGET_LIBRARY_DIRECTORIES ${OPENMESH_LIBRARY_DIRS})
    list(APPEND LIB_TARGET_LINK_DIRECTORIES ${OPENMESH_LIBRARY_DIRS})
    list(APPEND LIB_MODULES ${OPENMESH_LIBRARIES})
    list(APPEND LIB_TARGET_COMPILER_DEFINATION -D_USE_MATH_DEFINES)
endif()
if(NOT OPENMESH_FOUND)
    return()
endif()
