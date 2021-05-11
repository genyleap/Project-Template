# Modern Project-Template
 Modern C++ Project Template
##  Cross-Platform project structure based on CMake ##
This repository is a modern project template based on C++ and CMake build tool.

Note : This template is not yet complete and conceptually under development.


[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

## Language Standard Support [C++2a or C++2b]
- It depends on your compiler!

## Building

- You need CMake tool for building source code
- CMake 3.20 or higher is required.

```
cd build
cmake ..
make
./ProjectTemplate

```

## CMake module option [Dependencies]
- These features can be useful in downloading, building, and integrating prerequisites into your project.
- So you can set cmake option variable for enabling them.

- Include latest standard of C++
```
cmake .. -DUSE_LATEST_STANDARD=true
```

- Include Boost library
```
cmake .. -DUSE_BOOST=true
```

- Include Curl library
```
cmake .. -DUSE_CURL=true
```

- Include CppCheck library
```
cmake .. -DUSE_CPP_CHECK=true
```

- Include Google-Test
```
cmake .. -DUSE_GOOGLE_TEST=true
```

- Include Doc-Test
```
cmake .. -DUSE_DOC_TEST=true
```

- Include Catch2
```
cmake .. -DUSE_CATCH2=true
```

- Include Non-STL JSon library
```
cmake .. -DUSE_NONE_STL_JSON=true
```

- Include OpenSSL
```
cmake .. -DUSE_OPENSSL=true
```

- Include ZLib
```
cmake .. -DDUSE_ZLIB=true
```

## CMake module option [Compiler options]

- Enabling the test of clang-tidy
```
cmake .. -DENABLE_CLANG_TIDY=true
```

- Build the project as minimally as possible
```
cmake .. -DSIMPLE_BUILD=true
```

- Enable address sanitizer
```
cmake .. -DENABLE_ASAN=true
```

- Enabling the build of safe codes only [check by warnings]!
```
cmake .. -DENABLE_WARN_MODE=true
```

- Enabling the build of safe codes only!
```
cmake .. -DENABLE_SAFE_ONLY=true
```

- Enable developer (debug) mode
```
cmake .. -BUILD_DEBUG_MODE=true
```

- Enabling the build of debug logging
```
cmake .. -DEBUG_LOGGING=true
```

- Build Static Version
```
cmake .. -ENABLE_STATIC_LIB_BUILD=true
```

- Build Shared (Dynamic) Version
```
cmake .. -ENABLE_SHARED_LIB_BUILD=true
```

- Forcing to enable updated programming language.
```
cmake .. -FORCE_LATEST_STANDARD_FEATURE=true
```

- ِYou can set or change your project's basic information such as name, description, link, etc.

```
set(PROJECT_NAME "ProjectTemplate" CACHE STRING "Project Name")
set(PROJECT_TARGET ${PROJECT_NAME} CACHE STRING "Target Name")
```

- Creator Name.
```
set(PROJECT_CREATOR "Kambiz Asadzadeh")
```

- Project name, language, description, url and version.
```
project(
    ${PROJECT_NAME}
    LANGUAGES CXX
    DESCRIPTION "Description of your project."
    HOMEPAGE_URL "https://kambizasadzadeh.com"
    VERSION ${PROJECT_VERSION}
)
```

## Configuration output

```bash

-- The CXX compiler identification is AppleClang 12.0.0.12000032
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Ready for Apple Silicon.
-- Performing Test COMPILER_SUPPORTS_CXX23
-- Performing Test COMPILER_SUPPORTS_CXX23 - Success
-- Performing Test COMPILER_SUPPORTS_CXX20
-- Performing Test COMPILER_SUPPORTS_CXX20 - Success
-- Performing Test COMPILER_SUPPORTS_CXX17
-- Performing Test COMPILER_SUPPORTS_CXX17 - Success
-- Performing Test COMPILER_SUPPORTS_CXX14
-- Performing Test COMPILER_SUPPORTS_CXX14 - Success
-- Performing Test COMPILER_SUPPORTS_CXX11
-- Performing Test COMPILER_SUPPORTS_CXX11 - Success
-- Performing Test COMPILER_SUPPORTS_CXX0X
-- Performing Test COMPILER_SUPPORTS_CXX0X - Success

-- ------ ProjectTemplate Tools Configuration ------
-- Language Standard	    : C++[20]
-- Compiler		    : AppleClang
-- Compiler Version	    : 12.0.0.12000032
-- OS Target		    : Darwin-20.3.0
-- OS Version		    : 
-- System Architecture	    : x86_64
-- Project License	    : MIT
-- ------ ProjectTemplate Framework Info ------
-- Name			    : ProjectTemplate
-- Description		    : Description of your project.
-- Version		    : 
-- ------ ProjectTemplate Project Configuration ------
-- DEVELOPER		    : 
-- PROJECT_PROJECT	    : 
-- PROJECT_TARGET	    : ProjectTemplate
-- PROJECT_VERSION	    : 0.5.432
-- PROJECT_VERSION_TYPE	    : pre-alpha
-- ------ ProjectTemplate Building Configuration ------
-- PROJECT_BUILD_SHARED	: 
-- PROJECT_VERSION_TAG_HEX	: 0x00000000
-- PROJECT_FOLDER_SUFFIX	: 
-- LIBRARY_OUTPUT_PATH		: .../Project-Template/build/lib
-- CMAKE_CURRENT_SOURCE_DIR	: .../Project-Template
-- ------ ProjectTemplate End Configuration ------
-- Configuring done
```

## Usage Example
```cpp
#include <iostream>
#include "utilities/featuretest.hpp"

//!JSon [Non-STL] Features
#include <nlohmann/json.hpp>

//!Google Test
#ifdef USE_GOOGLE_TEST
# include <gtest/gtest.h>

class Counter {
public:
  // Returns the current counter value, and increments it.
  int Increment() {
    return m_counter++;
  }

  // Returns the current counter value, and decrements it.
  // counter can not be less than 0, return 0 in this case
  int Decrement() {
    if (m_counter == 0) {
      return m_counter;
    } else  {
      return m_counter--;
    }
  }

  // Prints the current counter value to STDOUT.
  void Print() const {
    printf("%d", m_counter);
  }
private:
  int m_counter;
};

//TEST UNIT
TEST(Counter, Increment) {
  Counter c;

  // Test that counter 0 returns 0
  EXPECT_EQ(0, c.Decrement());

  // EXPECT_EQ() evaluates its arguments exactly once, so they
  // can have side effects.

  EXPECT_EQ(0, c.Increment());
  EXPECT_EQ(1, c.Increment());
  EXPECT_EQ(2, c.Increment());

  EXPECT_EQ(3, c.Decrement());
}

#endif

//!Catch2
#ifdef USE_CATCH2
# include <catch2/catch_all.hpp>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

unsigned int Factorial( unsigned int number ) {
  return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

#endif

using namespace std;

void featureTest() {

  if (print.general_features) show("C++ GENERAL", cxx);
  if (print.cxx11 && print.core_features) show("C++11 CORE", cxx11);
  if (print.cxx14 && print.core_features) show("C++14 CORE", cxx14);
  if (print.cxx14 && print.lib_features ) show("C++14 LIB" , cxx14lib);
  if (print.cxx17 && print.core_features) show("C++17 CORE", cxx17);
  if (print.cxx17 && print.lib_features ) show("C++17 LIB" , cxx17lib);
  if (print.cxx20 && print.core_features) show("C++20 CORE", cxx20);
  if (print.cxx20 && print.lib_features ) show("C++20 LIB" , cxx20lib);
  if (print.cxx23 && print.core_features) show("C++23 CORE", cxx23);
  if (print.cxx23 && print.lib_features ) show("C++23 LIB" , cxx23lib);
  if (print.attributes) show("ATTRIBUTES", attributes);
}

int main()
{
  cout << "Hello World!" << endl;
#ifdef USE_FEATURE_TEST
  featureTest();
#endif
  return 0;
}
```

## More usage examples
- Coming soon...


## Contribution
- Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com
