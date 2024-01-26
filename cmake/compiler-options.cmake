include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++26" COMPILER_SUPPORTS_CXX26)
CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX26)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++26")
elseif(COMPILER_SUPPORTS_CXX23)
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
endif()

# Multi-threaded DLL runtime library (/MD or /MDd)
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
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
    message("-- CMake run for GNU")
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

# Use Feature Test library
option(USE_FEATURE_TEST "Use Feature Test library" OFF)
if (USE_FEATURE_TEST)
  add_definitions(-DUSE_FEATURE_TEST)
endif()

# Use Https/SSL system
option(USE_SSL_METHOD "Use Https/SSL system" OFF)
if (USE_SSL_METHOD)
  add_definitions(-DUSE_SSL_METHOD)
endif()

# Use test mode
option(ENABLE_TESTING "Use test mode" OFF)
if (ENABLE_TESTING)
  add_definitions(-DENABLE_TESTING)
endif()

# Enable the test of clang-tidy
option(ENABLE_CLANG_TIDY "Enabling the test of clang-tidy" OFF)
if (ENABLE_CLANG_TIDY)
  add_definitions(-DENABLE_CLANG_TIDY)
endif()

# Enable the test of cppcheck
option(ENABLE_CPPCHECK "Enabling the test of cppcheck" OFF)
if (ENABLE_CPPCHECK)
  add_definitions(-DENABLE_CPPCHECK)
endif()

# Build the project as minimally as possible
option(SIMPLE_BUILD "Build the project as minimally as possible" OFF)
if (SIMPLE_BUILD)
  add_definitions(-DSIMPLE_BUILD)
endif()

# Enable address sanitizer
option(ENABLE_ASAN "Enable address sanitizer" OFF)
if (ENABLE_ASAN)
  add_definitions(-DENABLE_ASAN)
endif()

# Build the project's documentation
option(BUILD_DOC "Build the project's documentation" OFF)
if (BUILD_DOC)
  add_definitions(-DBUILD_DOC)
endif()

# Compile Qt Quick (QML) files
option(USE_QT_QUICK_COMPILER "Compile Qt Quick (QML) files." OFF)
if (USE_QT_QUICK_COMPILER)
  add_definitions(-DUSE_QT_QUICK_COMPILER)
endif()

# Developer Mode
option(ENABLE_DEVELOPER_MODE "Developer Mode" ON)
if (ENABLE_DEVELOPER_MODE)
  add_definitions(-DENABLE_DEVELOPER_MODE)
endif()

# Todo Mode (Not activated feature!)
option(ENABLE_TODO_MODE "Todo Mode (Not activated feature!)" ON)
if (ENABLE_TODO_MODE)
  add_definitions(-DENABLE_TODO_MODE)
endif()

# Experimental Mode
option(ENABLE_EXPERIMENTAL_MODE "Experimental Mode" ON)
if (ENABLE_EXPERIMENTAL_MODE)
  add_definitions(-DENABLE_EXPERIMENTAL_MODE)
endif()

# Always produce ANSI-colored output (GNU/Clang only).
option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (FORCE_COLORED_OUTPUT)
  add_definitions(-DFORCE_COLORED_OUTPUT)
endif()

# Enable safe codes only!
option(ENABLE_SAFE_ONLY "Enable safe codes only!" OFF)
if (ENABLE_SAFE_ONLY)
  add_definitions(-DENABLE_SAFE_ONLY)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
      SET (CMAKE_CXX_FLAGS "/Wall /WX")
  else()
      SET (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
  endif()
endif()

# Enable full warnings for the compiler!
option(ENABLE_WARN_MODE "Enable full warnings for compiler!" OFF)
if (ENABLE_WARN_MODE)
  add_definitions(-DENABLE_WARN_MODE)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
      SET (CMAKE_CXX_FLAGS "/Wall")
  else()
      SET (CMAKE_CXX_FLAGS "-Wall")
  endif()
endif()

# Enable developer (debug) mode
option(BUILD_DEBUG_MODE "Enable developer (debug) mode" ON)
if (BUILD_DEBUG_MODE)
  add_definitions(-DBUILD_DEBUG_MODE)
endif()

# Enabling the build of debug logging
option(DEBUG_LOGGING "Enabling the build of debug logging" OFF)
if (DEBUG_LOGGING)
  add_definitions(-DDEBUG_LOGGING)
endif()

# Build Static Version
option(ENABLE_STATIC_LIB_BUILD "Build Static Version" OFF)
if (ENABLE_STATIC_LIB_BUILD)
  add_definitions(-DENABLE_STATIC_LIB_BUILD)
endif()

# Build Shared Version
option(ENABLE_SHARED_LIB_BUILD "Build Shared Version" OFF)
if (ENABLE_SHARED_LIB_BUILD)
  add_definitions(-DENABLE_SHARED_LIB_BUILD)
endif()

# Build Executable Version
option(ENABLE_BINARY_BUILD "Build Executable Version" ON)
if (ENABLE_BINARY_BUILD)
  add_definitions(-DENABLE_BINARY_BUILD)
endif()

# Header Only Version
option(ENABLE_HEADER_ONLY_BUILD "Header Only Version" OFF)
if (ENABLE_HEADER_ONLY_BUILD)
  add_definitions(-DENABLE_HEADER_ONLY_BUILD)
endif()

# Forcing to enable updated programming language.
option(FORCE_LATEST_STANDARD_FEATURE "Forcing to enable updated programming language." OFF)
if (FORCE_LATEST_STANDARD_FEATURE)
  add_definitions(-DFORCE_LATEST_STANDARD_FEATURE)
endif()

# Sanitizers Options
option(ENABLE_SANITIZERS "Enable Sanitizers" ON)
option(ENABLE_ADDRESS_SANITIZER "Enable AddressSanitizer (ASan)" OFF)
option(ENABLE_LEAK_SANITIZER "Enable LeakSanitizer (LSan)" OFF)
option(ENABLE_MEMORY_SANITIZER "Enable MemorySanitizer" OFF)
option(ENABLE_THREAD_SANITIZER "Enable ThreadSanitizer" OFF)
option(ENABLE_UNDEFINED_SANITIZER "Enable UndefinedBehaviorSanitizer" OFF)

if (ENABLE_SANITIZERS)
    add_definitions(-DENABLE_SANITIZERS)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak,undefined")
        if (ENABLE_MEMORY_SANITIZER AND NOT APPLE)
            add_definitions(-DENABLE_MEMORY_SANITIZER)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
        endif()
        if (ENABLE_THREAD_SANITIZER)
            add_definitions(-DENABLE_THREAD_SANITIZER)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
        endif()
        if (ENABLE_UNDEFINED_SANITIZER)
            add_definitions(-DENABLE_UNDEFINED_SANITIZER)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
        endif()
        if (APPLE)
            message(STATUS "Sanitizers are based on Clang on macOS.")
        endif()
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND NOT APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak,undefined")
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND APPLE)
            message(WARNING "Sanitizer is not supported with GCC on macOS. Ignoring the options.")
    else()
        message(WARNING "Unsupported compiler. Sanitizers are disabled.")
    endif()
else()
# Check and enable individual sanitizers
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        foreach(SANITIZER IN ITEMS ADDRESS LEAK MEMORY THREAD UNDEFINED)
            if ("ENABLE_${SANITIZER}_SANITIZER")
                add_definitions(-DENABLE_${SANITIZER}_SANITIZER)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${SANITIZER}")
            endif()
        endforeach()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND NOT APPLE)
        foreach(SANITIZER IN ITEMS ADDRESS LEAK MEMORY THREAD UNDEFINED)
            if ("ENABLE_${SANITIZER}_SANITIZER")
                add_definitions(-DENABLE_${SANITIZER}_SANITIZER)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${SANITIZER}")
            endif()
        endforeach()
else()
    message(WARNING "Unsupported compiler. Sanitizers are disabled.")
endif()
endif()
