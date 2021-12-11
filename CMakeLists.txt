cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0048 NEW)

# Add include path for cmake modules
# ------ PROJECT EXTRA CMAKE ------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

if(USE_QT)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
endif()

# ------ PROJECT INFO ------
# Options
set(PROJECT_NAME "ProjectTemplate" CACHE STRING "Project Name")
set(PROJECT_TARGET ${PROJECT_NAME} CACHE STRING "Target Name")

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 5)
set(PROJECT_VERSION_PATCH 432)

# ---- Project settings ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

set(PROJECT_CREATOR "Kambiz Asadzadeh")

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
set(PROJECT_VERSION_TYPE "pre-alpha")

set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} CACHE STRING "Version of ${PROJECT_NAME}")

project(
    ${PROJECT_NAME}
    LANGUAGES CXX
    DESCRIPTION "Description of your project."
    HOMEPAGE_URL "https://kambizasadzadeh.com"
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


SET (PROJECT_LICENSE "MIT")

set(SUFFIX_EXTRA *.in)
set(SUFFIX_HPPHEADER *.hpp)
set(SUFFIX_SOURCE *.cpp)
set(SUFFIX_CONFIG *.json)

if(HAS_USER_INTERFACE)
    set(SUFFIX_QML *.qml)
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

if(HAS_USER_INTERFACE)
    file(GLOB UI_SOURCE ui/${SUFFIX_QRC})
endif()

file(GLOB CONFIGFILE config/${SUFFIX_CONFIG})

if(HAS_USER_INTERFACE)
file(GLOB SOURCESFILE
    #---C++---
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
source_group("Base"   FILES ${HEADERS} ${SOURCES})
source_group("UI"     FILES ${UI_SOURCE})
source_group("Config" FILES ${CONFIGFILE})
source_group("Examples"  FILES ${EXAMPLES})

else()
    file(GLOB SOURCESFILE
    #---C++---
    ${HEADERS}
    ${SOURCES}
    ${UTILS}
    ${CONFIGFILE}
    ${PRECOMPILED}
    ${EXAMPLES}
    )

source_group("PrecompiledHeaders"  FILES ${PRECOMPILED})
source_group("Utilities"  FILES ${UTILS})
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


message(STATUS "${BoldRed}------ ${PROJECT_TARGET} Tools Configuration ------${ColourReset}")
message(STATUS "${Bold}Language Standard${ColourReset}	    : C++[${CMAKE_CXX_STANDARD}]")
message(STATUS "${Bold}Compiler${ColourReset}		    : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "${Bold}Compiler Version${ColourReset}	    : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "${Bold}OS Target${ColourReset}		    : ${CMAKE_HOST_SYSTEM}")
message(STATUS "${Bold}OS Version${ColourReset}		    : ${CMAKE_OSX_DEPLOYMENT_TARGET}")
message(STATUS "${Bold}System Architecture${ColourReset}	    : ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "${Bold}Project License${ColourReset}	    : ${PROJECT_LICENSE}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Framework Info ------${ColourReset}")
message(STATUS "${Bold}Name${ColourReset}			    : ${CMAKE_PROJECT_NAME}")
message(STATUS "${Bold}Description${ColourReset}		    : ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "${Bold}Version${ColourReset}		    : ${CMAKE_PROJECT_VERSION_VERSION}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Project Configuration ------${ColourReset}")
message(STATUS "${Bold}DEVELOPER${ColourReset}		    : ${PROJECT_DEVELOPER}")
message(STATUS "${Bold}PROJECT_PROJECT${ColourReset}	    : ${PROJECT_PROJECT}")
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

if(USE_QT)
#Add an executable to the project using the specified source files.
add_executable(${PROJECT_NAME} ${SOURCESFILE} ${UI_SOURCE})
else()
#Add an executable to the project using the specified source files.
add_executable(${PROJECT_NAME} ${SOURCESFILE})
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

target_link_libraries(${PROJECT_NAME}
 PRIVATE
 -lc++
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source PRIVATE source)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)

if(USE_QT)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()
endif()

#This command generates installation rules for a project.
#Install rules specified by calls to the install() command within a source directory. are executed in order during installation.
install(TARGETS ${PROJECT_NAME} DESTINATION build/bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/system-config.json DESTINATION ${CMAKE_BINARY_DIR}/config/)

#Ignore unused files.
list(APPEND CPACK_SOURCE_IGNORE_FILES /.git/ /build/ .gitignore .DS_Store)
