# Package Info.
set(OPENCV_NAME "OpenCV")
set(OPENCV_DESCRIPTION "Open Source Computer Vision Library.")
# Pakcage option.
option(USE_OPENCV ${OPENCV_DESCRIPTION} FALSE)
if (USE_OPENCV)
    add_definitions(-DUSE_OPENCV)
    # Define the repository URL and tag for the OpenCV libraries
    set(OPENCV_URL "https://github.com/opencv/opencv.git")
if(FORCE_UPGRADED_LIBS)
    set(OPENCV_TAG "master")
else()
    set(OPENCV_TAG "4.7.0")
endif()
    set(OPENCV_LIB_LIST "opencv_core;opencv_imgproc;opencv_imgcodecs;opencv_highgui;" CACHE STRING "List of modules (separated by a semicolon)")
endif()

set(OPENCV_MODULES_LIST "core;calib3d;dnn;features2d;flann;gapi;highgui;imgcodecs;imgproc;java;js;ml;objc;objdetect;photo;python;stitching;ts;video;videoio;world;" CACHE STRING "List of modules (separated by a semicolon)")

find_package(PkgConfig QUIET)
pkg_search_module(OpenCV opencv)
# Package data repository.
if(USE_OPENCV)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(opencv_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${OPENCV_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${opencv_base})
    # Declare the OPENCV libraries with their submodules using FetchContent_Declare
    FetchContent_Declare(
        OPENCV
        GIT_REPOSITORY              ${OPENCV_URL}
        GIT_TAG                     ${OPENCV_TAG}
        GIT_PROGRESS   TRUE
        USES_TERMINAL_DOWNLOAD TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(opencv)
    string(TOLOWER "${OPENCV_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
    FetchContent_MakeAvailable(opencv)
    include_directories(${${lcName}_SOURCE_DIR}/include)
    foreach(module IN LISTS OPENCV_LIB_LIST)
        list(APPEND LIB_MODULES ${module})
    endforeach()
    foreach(module IN LISTS OPENCV_MODULES_LIST)
        list(APPEND LIB_TARGET_INCLUDE_DIRECTORIES ${${lcName}_SOURCE_DIR}/modules/${module}/include)
    endforeach()
endif()
if(NOT OPENCV_FOUND)
    return()
endif()
