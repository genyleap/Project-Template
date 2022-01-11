cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0048 NEW)

# Add include path for cmake modules
# ------ PROJECT EXTRA CMAKE ------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

# ------ PROJECT INFO ------
# Options
set(PROJECT_NAME "ProjectTemplate" CACHE STRING "Project Name") #You can change "ProjectTemplate" with your project name.
set(PROJECT_TARGET ${PROJECT_NAME} CACHE STRING "Project Target Name")

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 9)
set(PROJECT_VERSION_PATCH 876)
set(PROJECT_VERSION_TWEAK 0)

# ---- Project settings ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

set(PROJECT_CREATOR "Kambiz Asadzadeh" CACHE STRING "Creator of your project.")
set(PROJECT_LICENSE_TYPE "MIT" CACHE STRING "Project License Type.") #Your project license type.

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
  execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE PROJECT_VERSION_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

endif()
if(NOT PROJECT_VERSION_TAG)
  set(PROJECT_VERSION_TAG 00000000)
endif()
set(PROJECT_VERSION_TAG_HEX 0x${PROJECT_VERSION_TAG})
set(PROJECT_VERSION_TYPE "alpha" CACHE STRING "Version type.")

set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

set(PROJECT_VERSION_STRING ${PROJECT_VERSION})

# Supported languages include C, CXX (i.e. C++), CUDA, OBJC (i.e. Objective-C), OBJCXX, Fortran, HIP, ISPC, and ASM. By default C and CXX are enabled if no language options are given.
# Specify language NONE, or use the LANGUAGES keyword and list no languages, to skip enabling any languages.
set(PROJECT_LANGUAGES CXX)

#Use these keys [stl, qt, qtwidget, qtquick]
set(PROJECT_MAIN_TYPE "stl" CACHE STRING "Library System.")

#Use these keys [macOS, Windows, Linux, iOS, Android]
set(PLATFORM_OS "macOS" CACHE STRING "OS Type.")

set(PROJECT_DESCRIPTION "A template for modern C++ projects with useful features for developing cross-platform projects." CACHE STRING "Project Description")

set(PROJECT_HOMEPAGE_URL "https://kambizasadzadeh.com" CACHE STRING "Project URL.")


#Project pre-configuration system.
configure_file(
  ${PROJECT_SOURCE_DIR}config.hpp.in
  ${PROJECT_SOURCE_DIR}config.hpp
)

project(
    ${PROJECT_NAME}
    LANGUAGES CXX
    DESCRIPTION "A template for modern C++ projects with useful features for developing cross-platform projects." #You can replace your project description with this string.
    HOMEPAGE_URL "https://kambizasadzadeh.com" #Your project website address.
    VERSION ${PROJECT_VERSION}
    )

# ------ CROSS-COMPILE CONFIG ------
include(cross-compile)
if(cross-compile)
  return()
endif()
set(cross-compile ON)

# ------ PROJECT CONFIG ------
include(color-message)
if(color-message)
  return()
endif()
set(color-message ON)

# ------ COMPILER CONFIG ------
include(compiler-options)
if(compiler-options)
  return()
endif()
set(compiler-options ON)

# ------ PACKAGES CONFIG ------
include(packages)
if(packages)
  return()
endif()
set(packages ON)

if(USE_QT AND NOT PROJECT_MAIN_TYPE STREQUAL "stl")
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
endif()

set(SUFFIX_EXTRA *.in)
set(SUFFIX_HPPHEADER *.hpp)
set(SUFFIX_SOURCE *.cpp)
set(SUFFIX_CONFIG *.json)

if(HAS_USER_INTERFACE)
    if(PROJECT_MAIN_TYPE STREQUAL "qtwidget")
        set(SUFFIX_WIDGET *.ui)
    elseif(PROJECT_MAIN_TYPE STREQUAL "qtquick")
        set(SUFFIX_QML *.qml)
    endif()
    set(SUFFIX_QRC *.qrc)
endif()

file(GLOB PRECOMPILED precompiled/pch.hpp)
file(GLOB HEADERS source/${SUFFIX_HPPHEADER})
file(GLOB SOURCES source/${SUFFIX_SOURCE})

file(GLOB EXAMPLES
     source/examples/${SUFFIX_HPPHEADER}
     source/examples/${SUFFIX_SOURCE}
)
file(GLOB UTILS
     utilities/${SUFFIX_HPPHEADER}
     utilities/${SUFFIX_SOURCE}
)

if(${PROJECT_MAIN_TYPE} STREQUAL "stl")
    set(HAS_USER_INTERFACE false)
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/stl/${SUFFIX_HPPHEADER}
         source/entrypoint/stl/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qt")
    set(HAS_USER_INTERFACE false)
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/qt/nogui/${SUFFIX_HPPHEADER}
         source/entrypoint/qt/nogui/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
    set(HAS_USER_INTERFACE true)
    file(GLOB MAIN_ENTRY_POINT
        source/entrypoint/qt/qtwidget/${SUFFIX_HPPHEADER}
        source/entrypoint/qt/qtwidget/${SUFFIX_SOURCE}
        ui/classic/${SUFFIX_HPPHEADER}
        ui/classic/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
    set(HAS_USER_INTERFACE true)
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/qt/qtquick/${SUFFIX_HPPHEADER}
         source/entrypoint/qt/qtquick/${SUFFIX_SOURCE}
    )
endif()


if(HAS_USER_INTERFACE)
    if(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
        file(GLOB UI_SOURCE ui/classic/${SUFFIX_WIDGET})
    else()
        file(GLOB UI_SOURCE ui/modern/${SUFFIX_QRC})
    endif()
endif()

file(GLOB CONFIGFILE config/${SUFFIX_CONFIG})

if(HAS_USER_INTERFACE)
file(GLOB SOURCESFILE
    #---C++---
    ${MAIN_ENTRY_POINT}
    ${HEADERS}
    ${SOURCES}
    ${UI_SOURCE}
    ${UTILS}
    ${CONFIGFILE}
    ${PRECOMPILED}
    ${EXAMPLES}
    )

source_group("PrecompiledHeaders"  FILES ${PRECOMPILED})
source_group("Utilities"  FILES ${UTILS})
source_group("Entry Point (Main)"   FILES ${MAIN_ENTRY_POINT})
source_group("Base"   FILES ${HEADERS} ${SOURCES})
source_group("UI"     FILES ${UI_SOURCE})
source_group("Config" FILES ${CONFIGFILE})
source_group("Examples"  FILES ${EXAMPLES})

else()
    file(GLOB SOURCESFILE
    #---C++---
    ${MAIN_ENTRY_POINT}
    ${HEADERS}
    ${SOURCES}
    ${UTILS}
    ${CONFIGFILE}
    ${PRECOMPILED}
    ${EXAMPLES}
    )

source_group("Precompiled Headers"  FILES ${PRECOMPILED})
source_group("Utilities"  FILES ${UTILS})
source_group("Entry Point (Main)"   FILES ${MAIN_ENTRY_POINT})
source_group("Base"   FILES ${HEADERS} ${SOURCES})
source_group("Config" FILES ${CONFIGFILE})
source_group("Examples"  FILES ${EXAMPLES})

endif()

# ------ PROJECT DIRECTORIES ------
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
SET(EXECUTABLE_OUTPUT_PATH ${dir})
SET(LIBRARY_OUTPUT_PATH ${dir}lib)
SET(CMAKE_CACHEFILE_DIR ${dir})

message("CMAKE_BUILD_FILES_DIRECTORY: " ${CMAKE_BUILD_FILES_DIRECTORY})
# ------ OUTPUTS CONFIG ------

if(PLATFORM_OS STREQUAL "macOS")
    if(OS_ARCHITECTURES STREQUAL "")
      set(OS_ARCHITECTURES ${CMAKE_OSX_ARCHITECTURES})
      else()
      set(OS_ARCHITECTURES "x86_64")
    endif()
else()
    set(OS_ARCHITECTURES ${PROCESSOR_ARCHITECTURE})
endif()

message(STATUS "${BoldRed}------ ${PROJECT_TARGET} Tools Configuration ------${ColourReset}")
message(STATUS "${Bold}Language Standard${ColourReset}	    : C++[${CMAKE_CXX_STANDARD}]")
message(STATUS "${Bold}Compiler${ColourReset}		    : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "${Bold}Compiler Version${ColourReset}	    : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "${Bold}OS Target${ColourReset}		    : ${CMAKE_HOST_SYSTEM}")
message(STATUS "${Bold}OS Version${ColourReset}		    : ${CMAKE_HOST_SYSTEM_VERSION}")
message(STATUS "${Bold}System Architecture${ColourReset}      : ${OS_ARCHITECTURES}")
message(STATUS "${Bold}Project License${ColourReset}	    : ${PROJECT_LICENSE_TYPE}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Framework Info ------${ColourReset}")
message(STATUS "${Bold}Name${ColourReset}			    : ${CMAKE_PROJECT_NAME}")
message(STATUS "${Bold}Description${ColourReset}		    : ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "${Bold}Version${ColourReset}		    : ${PROJECT_VERSION}")
message(STATUS "${Bold}Creator${ColourReset}		    : ${PROJECT_CREATOR}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Project Configuration ------${ColourReset}")
message(STATUS "${Bold}DEVELOPER${ColourReset}		    : ${PROJECT_CREATOR}")
message(STATUS "${Bold}PROJECT_PROJECT${ColourReset}	    : ${PROJECT_NAME}")
message(STATUS "${Bold}PROJECT_TARGET${ColourReset}	    : ${PROJECT_TARGET}")
message(STATUS "${Bold}PROJECT_VERSION${ColourReset}	    : ${PROJECT_VERSION}")
message(STATUS "${Bold}PROJECT_VERSION_TYPE${ColourReset}	    : ${Underscore}${PROJECT_VERSION_TYPE}${ColourReset}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Building Configuration ------${ColourReset}")
message(STATUS "${Bold}PROJECT_BUILD_SHARED${ColourReset}	: ${PROJECT_BUILD_SHARED}")
message(STATUS "${Bold}PROJECT_VERSION_TAG_HEX${ColourReset}	: ${PROJECT_VERSION_TAG_HEX}")
message(STATUS "${Bold}PROJECT_FOLDER_SUFFIX${ColourReset}	: ${PROJECT_FOLDER_SUFFIX}")
message(STATUS "${Bold}LIBRARY_OUTPUT_PATH${ColourReset}		: ${LIBRARY_OUTPUT_PATH}")
message(STATUS "${Bold}CMAKE_CURRENT_SOURCE_DIR${ColourReset}	: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} End Configuration ------${ColourReset}")

if(ANDROID)
    set(DANDROID_NATIVE_API_LEVEL 23)
    if(NOT PROJECT_MAIN_TYPE STREQUAL "qtquick")
        #message(${BoldRed} "Please set {qtquick} key to PROJECT_MAIN_TYPE." ${ColourReset})
        set(PROJECT_MAIN_TYPE "qtquick")
    endif()
    add_library(${PROJECT_NAME} SHARED ${SOURCESFILE} ${UI_SOURCE})
else()
  if(USE_QT)
    #Add an executable to the project using the specified source files.
    add_executable(${PROJECT_NAME} ${SOURCESFILE} ${UI_SOURCE})
  else()
    #Add an executable to the project using the specified source files.
    add_executable(${PROJECT_NAME} ${SOURCESFILE})
  endif()
endif()

#Support Qt6 & Qt5 Modules.
if(USE_QT)


    if(QT_VERSION_MAJOR EQUAL 6)
        qt_import_qml_plugins(${PROJECT_NAME})
        qt_finalize_executable(${PROJECT_NAME})
    endif()

    if(USE_QT5_FEATURES)

        if(${PROJECT_MAIN_TYPE} STREQUAL "qt")
            list(APPEND QT_MODULES Core Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
            list(APPEND QT_MODULES Core Widgets Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Widgets
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
            list(APPEND QT_MODULES Core Quick Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Quick
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        else()
            list(APPEND QT_MODULES Core Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        endif()
    else()
        if(${PROJECT_MAIN_TYPE} STREQUAL "qt")
            list(APPEND QT_MODULES Core)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
            list(APPEND QT_MODULES Core Widgets)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Widgets
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
            list(APPEND QT_MODULES Core Quick)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Quick
                )
        endif()
    endif()
    find_package(QT NAMES Qt6 Qt5 COMPONENTS ${QT_MODULES} REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${QT_MODULES} REQUIRED)

    if(USE_QT_QUICK_COMPILER)
    find_package(QtQuickCompiler)
    qt_add_resources(UI_SOURCE ui/modern/qml.qrc)
    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_MODULES_LINK})
endif()



if(USE_BOOST)
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs.
set(Boost_USE_DEBUG_LIBS        OFF) # ignore debug libs and.
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs.
set(Boost_USE_MULTITHREADED      ON)  # use multithread mode.
set(Boost_USE_STATIC_RUNTIME    OFF)  # use static mode at runtime.
    target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
endif()
if(USE_NONE_STL_JSON)
    target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
endif()
if(USE_CATCH2)
    target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
endif()
if(USE_GOOGLE_TEST)
    target_link_libraries(${PROJECT_NAME} PRIVATE gtest)
endif()
if(USE_DOC_TEST)
    target_link_libraries(${PROJECT_NAME} PRIVATE doctest)
endif()
if(USE_CURL)
    target_link_libraries(${PROJECT_NAME} PRIVATE curl)
endif()
if(USE_FMT)
    target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
endif()
if(USE_OPENSSL)
    target_link_libraries(${PROJECT_NAME} PRIVATE crypto ssl)
endif()
if(USE_ZLIB)
    target_link_libraries(${PROJECT_NAME} PRIVATE zlib)
endif()
if(USE_CTRE)
    target_link_libraries(${PROJECT_NAME} PRIVATE ctre)
endif()
if(USE_BOOST)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
endif()



target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source PRIVATE source)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)

if(PLATFORM_OS STREQUAL "Android")
    include(${ANDROID_SDK}/android_openssl/CMakeLists.txt)
endif()

#This command generates installation rules for a project.
#Install rules specified by calls to the install() command within a source directory. are executed in order during installation.
install(TARGETS ${PROJECT_NAME} DESTINATION build/bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/system-config.json DESTINATION ${CMAKE_BINARY_DIR}/config/)

#Ignore unused files.
list(APPEND CPACK_SOURCE_IGNORE_FILES /.git/ /build/ .gitignore .DS_Store)
