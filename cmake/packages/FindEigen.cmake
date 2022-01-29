#Package Info.
set(EIGEN_NAME "Eigen")
set(EIGEN_DESCRIPTION "Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.")

#Pakcage option.
option(USE_EIGEN ${EIGEN_DESCRIPTION} FALSE)
if (USE_EIGEN)
    add_definitions(-DUSE_EIGEN)
endif()

find_package(PkgConfig QUIET)
pkg_search_module(${EIGEN_NAME} eigen)
#Package data repository.
if(USE_EIGEN)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(eigen_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${EIGEN_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${eigen_base})
    FetchContent_Declare(
        eigen
        GIT_REPOSITORY      https://gitlab.com/libeigen/eigen.git
        GIT_TAG master
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
    list(APPEND LIB_MODULES eigen)
endif()
if(NOT EIGEN_FOUND)
    return()
endif()
