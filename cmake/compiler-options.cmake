cmake_minimum_required(VERSION 3.23)
if(${CMAKE_VERSION} VERSION_LESS 3.23)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.23)
endif()

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX23)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
elseif(COMPILER_SUPPORTS_CXX23)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif(COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(OPTIMIZATION_LEVEL "0" CACHE STRING "Optimization Level")
if (OPTIMIZATION_LEVEL)
  add_definitions(-DOPTIMIZATION_LEVEL)
endif()

# -lstdc++: Links against the GNU Standard C++ Library.
# -lc++: Links against the libc++ library (used in Clang/LLVM compiler).
# -lc++abi: Links against the libc++abi library, which provides low-level support for the C++ runtime (used in Clang/LLVM compiler).
# Note: Both GCC and MSVC, you generally don't need to explicitly include flags like -lc++abi or their equivalents.

# C++ STL Library Features.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-lstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++")
    # find_package(TBB REQUIRED COMPONENTS tbb)
    # list(APPEND LIB_STL_MODULES_LINKER tbb)
endif()


if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    #Todo...
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-lc++ -lc++abi")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-lc++ -lc++abi")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("-- CMake run for msvc")
    if(OPTIMIZATION_LEVEL EQUAL "0")
        set(CMAKE_CXX_FLAGS_DEBUG "/Z7 /Od")
        set(CMAKE_CXX_FLAGS_RELEASE "/Od")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "1")
        set(CMAKE_CXX_FLAGS_DEBUG "/Zi /O1")
        set(CMAKE_CXX_FLAGS_RELEASE "/O1")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "2")
        set(CMAKE_CXX_FLAGS_DEBUG "/Zi /O2")
        set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "3")
        set(CMAKE_CXX_FLAGS_DEBUG "-ZI -Oi")
        set(CMAKE_CXX_FLAGS_RELEASE "-Oi")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "4")
        set(CMAKE_CXX_FLAGS_DEBUG "-ZI /Os")
        set(CMAKE_CXX_FLAGS_RELEASE "/Os")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "5")
        set(CMAKE_CXX_FLAGS_DEBUG "-ZI /Ot")
        set(CMAKE_CXX_FLAGS_RELEASE "/Ot")
    endif()
else()
    message("-- CMake run for non-msvc")
    if(OPTIMIZATION_LEVEL EQUAL "0")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
        set(CMAKE_CXX_FLAGS_RELEASE "-O0")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "1")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O1")
        set(CMAKE_CXX_FLAGS_RELEASE "-O1")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "2")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O2")
        set(CMAKE_CXX_FLAGS_RELEASE "-O2")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "3")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O3")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "4")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -Os")
        set(CMAKE_CXX_FLAGS_RELEASE "-Os")
    endif()
    if(OPTIMIZATION_LEVEL EQUAL "5")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast")
        set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")
    endif()
endif()

#########################
# --- Build Options --- #
#########################

option(USE_FEATURE_TEST "Use Feature Test library" OFF)
if (USE_FEATURE_TEST)
  add_definitions(-DUSE_FEATURE_TEST)
endif()

option(USE_SSL_METHOD	    "Use Https/SSL system"      OFF)
if (USE_SSL_METHOD)
  add_definitions(-DUSE_SSL_METHOD)
endif()

option(ENABLE_TESTING	    "Use test mode" FALSE)
if (ENABLE_TESTING)
  add_definitions(-DENABLE_TESTING)
endif()

option(ENABLE_CLANG_TIDY    "Enabling the test of clang-tidy"  FALSE)
if (ENABLE_CLANG_TIDY)
  add_definitions(-DENABLE_CLANG_TIDY)
endif()

option(ENABLE_CPPCHECK	    "Enabling the test of cppcheck"  FALSE)
if (ENABLE_CPPCHECK)
  add_definitions(-DENABLE_CPPCHECK)
endif()

option(SIMPLE_BUILD	    "Build the project as minimally as possible" FALSE)
if (SIMPLE_BUILD)
  add_definitions(-DSIMPLE_BUILD)
endif()

option(ENABLE_ASAN	    "Enable address sanitizer"  FALSE)
if (ENABLE_ASAN)
  add_definitions(-DENABLE_ASAN)
endif()

option(BUILD_DOC	    "Build the project's documentation"  OFF)
if (BUILD_DOC)
  add_definitions(-DBUILD_DOC)
endif()

option(USE_QT_QUICK_COMPILER "Compile Qt Quick (QML) files." OFF)
if (USE_QT_QUICK_COMPILER)
  add_definitions(-DUSE_QT_QUICK_COMPILER)
endif()

option(ENABLE_DEVELOPER_MODE	    "Developer Mode"      ON)
if (ENABLE_DEVELOPER_MODE)
  add_definitions(-DENABLE_DEVELOPER_MODE)
endif()

option(ENABLE_TODO_MODE	    "Todo Mode (Not activated feature!)"      ON)
if (ENABLE_TODO_MODE)
  add_definitions(-DENABLE_TODO_MODE)
endif()

option(ENABLE_EXPERIMENTAL_MODE	    "Experimental Mode"      ON)
if (ENABLE_EXPERIMENTAL_MODE)
  add_definitions(-DENABLE_EXPERIMENTAL_MODE)
endif()

option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)."  TRUE)
if (FORCE_COLORED_OUTPUT)
  add_definitions(-DFORCE_COLORED_OUTPUT)
endif()

option(ENABLE_SAFE_ONLY	    "Enable safe codes only!"  FALSE)
if (ENABLE_SAFE_ONLY)
  add_definitions(-DENABLE_SAFE_ONLY)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
      SET (CMAKE_CXX_FLAGS "/Wall /WX")
  else()
      SET (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
  endif()
endif()

option(ENABLE_WARN_MODE	    "Enable full warnings for compiler!"  FALSE)
if (ENABLE_WARN_MODE)
  add_definitions(-DENABLE_WARN_MODE)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
      SET (CMAKE_CXX_FLAGS "/Wall")
  else()
      SET (CMAKE_CXX_FLAGS "-Wall")
  endif()
endif()

option(BUILD_DEBUG_MODE "Enable developer (debug) mode" ON)
if (BUILD_DEBUG_MODE)
  add_definitions(-DBUILD_DEBUG_MODE)
endif()

option(DEBUG_LOGGING	    "Enabling the build of debug logging" FALSE)
if (DEBUG_LOGGING)
  add_definitions(-DDEBUG_LOGGING)
endif()

option(ENABLE_STATIC_LIB_BUILD "Build Static Version" OFF)
if (ENABLE_STATIC_LIB_BUILD)
  add_definitions(-DENABLE_STATIC_LIB_BUILD)
endif()

option(ENABLE_SHARED_LIB_BUILD "Build Shared Version" OFF)
if (ENABLE_SHARED_LIB_BUILD)
  add_definitions(-DENABLE_SHARED_LIB_BUILD)
endif()

option(ENABLE_BINARY_BUILD "Build Executable Version" ON)
if (ENABLE_BINARY_BUILD)
  add_definitions(-DENABLE_BINARY_BUILD)
endif()

option(ENABLE_HEADER_ONLY_BUILD "Header Only Version" OFF)
if (ENABLE_HEADER_ONLY_BUILD)
  add_definitions(-DENABLE_HEADER_ONLY_BUILD)
endif()

option(FORCE_LATEST_STANDARD_FEATURE "Forcing to enable updated programming language." FALSE)
if (FORCE_LATEST_STANDARD_FEATURE)
  add_definitions(-DFORCE_LATEST_STANDARD_FEATURE)
endif()

