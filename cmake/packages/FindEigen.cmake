# Package Info.
set(EIGEN_NAME "Eigen")
set(EIGEN_DESCRIPTION "Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.")

# Pakcage option.
option(USE_EIGEN ${EIGEN_DESCRIPTION} FALSE)
if (USE_EIGEN)
    add_definitions(-DUSE_EIGEN)
    # Define the repository URL and tag for the Eigen libraries
    set(EIGEN_URL "https://gitlab.com/libeigen/eigen.git")
if(FORCE_UPGRADED_LIBS)
    set(EIGEN_TAG "master")
else()
    set(EIGEN_TAG "3.4")
endif()
    set(EIGEN_LIB_LIST "eigen" CACHE STRING "List of modules (separated by a semicolon)")
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${EIGEN_NAME} eigen)
# Package data repository.
if(USE_EIGEN)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(eigen_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${EIGEN_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${eigen_base})
    FetchContent_Declare(
        eigen
        GIT_REPOSITORY      ${EIGEN_URL}
        GIT_TAG             ${EIGEN_TAG}
        GIT_PROGRESS   TRUE
        USES_TERMINAL_DOWNLOAD TRUE
        )

    # Check if population has already been performed
    FetchContent_GetProperties(eigen)
    string(TOLOWER "${EIGEN_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(eigen)
    foreach(module IN LISTS EIGEN_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
endif()
if(NOT EIGEN_FOUND)
    return()
endif()
