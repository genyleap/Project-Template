# Standard settings
set (CMAKE_SYSTEM_NAME ANDROID)
set (CMAKE_SYSTEM_VERSION 1)
set (CMAKE_CROSSCOMPILING TRUE)
set (ANDROID TRUE)
set (PLATFORM_FOLDER "Android")

if(ANDROID_SDK_ROOT)
include(${ANDROID_SDK_ROOT}/android_openssl/CMakeLists.txt)
endif()

if(ANDROID_SDK)
include(${ANDROID_SDK}/android_openssl/CMakeLists.txt)
endif()

#------ PROJECT DIRECTORIES ------
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/${PLATFORM_FOLDER})
message("Make sure that build/Android path is set manually.")
#Qt Creator cannot set android path as default base on dir.
#You shoud set custom as buid/android from QtCreator.
#set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
#set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
#set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
#set(CMAKE_BUILD_DIRECTORY ${dir})
#set(CMAKE_BINARY_DIR  ${dir})
#SET(EXECUTABLE_OUTPUT_PATH ${dir})
#SET(LIBRARY_OUTPUT_PATH ${dir}/lib)
#SET(CMAKE_CACHEFILE_DIR ${dir})
