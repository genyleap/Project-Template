# Modern Project-Template (PT)
A template for modern C++ projects with useful features for developing cross-platform projects.

##  Cross-Platform project structure based on CMake ##
This repository is a modern project template based on C++ and CMake build tool.

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

## Top features:
- ✅ Very easy management of dependencies.
- ✅ Top level macro usage.
- ✅ Customized project structure based on your program type.
- ✅ Advanced microprocessors.
- ✅ Cross-Platform
- ✅ Adapted to latest language & compiler standards.

## Supported platforms:

- [x] macOS
- [x] Windows
- [x] Linux
- [x] freeBSD
- [ ] OpenBSD
- [ ] NetBSD
- [x] iOS
- [ ] watchOS
- [x] Android

## Supported project type:

- [x] Core Application
- [x] Desktop Application
- [x] Embedded Application
- [x] Mobile Application
- [x] Library

## Language Standard Support [C++2a or C++2b]
- It depends on your compiler!

## Building

- You need CMake tool for building source code
- CMake 3.23 or higher is required.

```
cd build
cmake ..
make
./ProjectTemplate

```

> How to sync project from template source?
- This feature is embedded in the project as Git Action.

## Customization options.
```
cmake .. -DPROJECT_NAME="Your Project Name" -DPROJECT_CREATOR="Kambiz" -DPROJECT_VERSION_TYPE="beta" -DPROJECT_DESCRIPTION="This is my awesome project" -DPROJECT_LICENSE_TYPE="mit"
```

## Customization Note
- Change PROJECT_NAME variable to your own project name.
- Change PROJECT_CREATOR variable to your main project developer.
- Change PROJECT_DESCRIPTION variable to your project description.
- Change PROJECT_HOMEPAGE_URL variable to your project official url.
- Change PROJECT_VERSION_TYPE variable to your project version based on semantic versioning.

- The project output structure is based on "application" with gui by default, so if you want to change it, you should change the PROJECT_USAGE_TYPE and PROJECT_MAIN_TYPE variables.
- Change the DEVELOPER_BUNDLE_IDENTIFIER variable for your own developer id, especially in Apple products, you should set it according to the bundle string in Xcode.
- The language standard is based on C++17 by default, you can change it via CMAKE_CXX_STANDARD variable.
- Finally, specify software version for the variables PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK.
- Enjoy your project! :)

## CMake module option [Dependencies]
- These features can be useful in downloading, building, and integrating prerequisites into your project.
- So you can set cmake option variable for enabling them.

- Include latest standard of C++
```
cmake .. -DUSE_LATEST_STANDARD=true
```

- Include Boost library
- This option is currently usable if it's already installed on your system.
- I'll work on the automatic downloader version as soon as possible.
```
cmake .. -DUSE_BOOST=true
```

- Include Qt Framework
```
cmake .. -DGUI_APPLICATION=true
```

- Force to update latest version of dependencies from repositories.
```
cmake .. -DFORCE_UPGRADED_LIBS=false
```


- Include UI
```
cmake .. -DHAS_USER_INTERFACE=true
```

- Include project main type by [stl, qt, qtwidget, qtquick]
- stl (Your project will be based on stl [Default]).
- qt (Your project will be based on Qt Core only [No GUI]).
- qtwidget (Your project will be based on C++, QtWidget [Classic GUI]).
- qtquick (Your project will be based on C++, QtQuick and QML [Modern GUI]).
```
cmake .. -DPROJECT_MAIN_TYPE=stl
```

- Project Type
- Use these keys [application, library]
```
cmake .. -DPROJECT_USAGE_TYPE=application
```

- Project Type
- Use these keys [application, library]
```
cmake .. -DDEVELOPER_BUNDLE_IDENTIFIER=com.kambizasadzadeh.app
```

- The Qt Quick Compiler is a development add-on for Qt Quick applications which allows you to compile QML source code into the final binary. When you use this add-on, the application's startup time is significantly improved and you no longer need to deploy .qml files together with the application.
```
cmake .. -DUSE_QT_QUICK_COMPILER=false
```

- Include Curl library
```
cmake .. -DUSE_CURL=true
```

- Include FMT library
```
cmake .. -DUSE_FMT=true
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

- Include CTRE
```
cmake .. -DUSE_CTRE=true
```

- Include JSon library
```
cmake .. -DUSE_JSON=true
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
cmake .. -DBUILD_DEBUG_MODE=true
```

- Enabling the build of debug logging
```
cmake .. -DDEBUG_LOGGING=true
```

- Build Static Version
```
cmake .. -DENABLE_STATIC_LIB_BUILD=true
```

- Developer mode
```
cmake .. -DENABLE_DEVELOPER_MODE=true
```

- Todo mode
```
cmake .. -DENABLE_TODO_MODE=true
```

- Experimental mode
```
cmake .. -DENABLE_EXPERIMENTAL_MODE=true
```

- Build Shared (Dynamic) Version
```
cmake .. -ENABLE_SHARED_LIB_BUILD=true
```

- Forcing to enable updated programming language.
```
cmake .. -FORCE_LATEST_STANDARD_FEATURE=true
```

- Optimization level.
```
cmake .. -DOPTIMIZATION_LEVEL=0
```
- O Disables optimization, no optimization, fast compilation and nicely debuggable code. (default)
- 1 Some optimization. Is equivalent to 0 with no parameters. Optimization for code size and execution time, generate minimum size code.
- 2 Moderate optimization, enables all standard optimizations. Optimization more for code size and execution time, optimizes code for maximum speed.
- 3 Over and above 2, does aggressive optimizations that may not be compliant to language standard. Optimization more for code size and execution time
- 4 Over and above 3, does aggressive optimizations that may not be compliant to language standard. Optimizations for size over optimizations for speed.
- 5 O3 with fast none accurate math calculations, optimizations for speed over optimizations for size.

You can set or change your project's basic information such as name, description, link, etc.

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
-- PROJECT_VERSION	    : 1.0.2.0
-- PROJECT_VERSION_TYPE	    : final
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
#if defined(HAS_USER_INTERFACE) && defined(USE_QT)
//! Qt
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
#else

#include <iostream>
#include "utilities/featuretest.hpp"

//! Examples
#include "examples/compilertest.hpp"
#include "examples/platformtest.hpp"
#include "examples/librarytest.hpp"
#include "examples/languagetest.hpp"
#include "examples/configtest.hpp"

//!JSon [Non-STL] Features
#include <nlohmann/json.hpp>

//!Google Test
#ifdef USE_GOOGLE_TEST
#include <gtest/gtest.h>

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

int main()
{
  cout << "Hello World!" << endl;

  //!Config Test
  ConfigTest config;
  config.readSettings();

  //!Compiler Test
  CompilerTest compiler;
  compiler.getCompilerInfo();

  //!Platform Test
  PlatformTest platform;
  platform.getPlatformInfo();

  //!Library Test
  LibraryTest library;
  library.testBoost(); // Boost

  //!Language Features
  LanguageTest language;
  language.checkFeatures();
  
  //!ThirdParty Library
  ThirdPartyTest thirdPartyTest;
  thirdPartyTest.testFmt();

  return 0;
}

#endif
```

## More usage examples
- Compiler Test
```cpp
cout << "Compiler Name : " << __COMPILER__ << endl;
cout << "Compiler Version : " << __COMPILER_VER__ << endl;

#if defined(__COMPILER_CLANG_LLVM_)
  cout << "Clang compiler has been detected!\n";
#elif defined(__COMPILER_INTEL__)
  cout << "Intel compiler has been detected!\n";
#elif defined(__COMPILER_MINGW__)
  cout << "MinGW compiler has been detected!\n";
#elif defined(__COMPILER_MINGW_64__)
  cout << "MinGW64 compiler has been detected!\n";
#elif defined(__COMPILER_GCC__)
  cout << "GCC compiler has been detected!\n";
#elif defined(__COMPILER__HEWLETT_)
  cout << "Hewlett compiler has been detected!\n";
#elif defined(__COMPILER_IBM__)
  cout << "IBM compiler has been detected!\n";
#elif defined(__COMPILER_MSVC__)
  cout << "MSVC compiler has been detected!\n";
#elif defined(__COMPILER_PGCC__)
  cout << "PGCC compiler has been detected!\n";
#elif defined(__COMPILER_ORACLE__)
  cout << "Oracle compiler has been detected!\n";
#endif
  
```
- Platform Test
```cpp
#if defined(PLATFORM_MAC)
  cout << "This is macOS platform!\n";
#elif defined(PLATFORM_WINDOWS)
  cout << "This is Windows platform!\n";
#elif defined(PLATFORM_LINUX)
  cout << "This is Linux platform!\n";
#elif defined(PLATFORM_FREEBSD)
  cout << "This is freeBSD platform!\n";
#elif defined(PLATFORM_OPENBSD)
  cout << "This is openBSD platform!\n";
#elif defined(PLATFORM_VXWORKS)
  cout << "This is VXWorks platform!\n";
#elif defined(PLATFORM_MOTOROLA)
  cout << "This is Motorola platform!\n";
#elif defined(PLATFORM_ULTRIX)
  cout << "This is Ultrix platform!\n";
#elif defined(PLATFORM_DOS)
  cout << "This is Dos platform!\n";
#elif defined(PLATFORM_WINDOWS_PHONE)
  cout << "This is Windows Phone platform!\n";
#elif defined(PLATFORM_IOS_SIMULATOR)
  cout << "This is iOS Simulator platform!\n";
#elif defined(PLATFORM_IOS)
  cout << "This is iOS platform!\n";
#elif defined(PLATFORM_APPLE_TV)
  cout << "This is AppleTV platform!\n";
#elif defined(PLATFORM_IWATCH)
  cout << "This is iWatch platform!\n";
#elif defined(PLATFORM_ANDROID)
  cout << "This is Android platform!\n";
#endif
```
- Library Test
```cpp
#include "include/common.hpp"
#include <iostream>

#ifdef USE_BOOST
#include <boost/chrono.hpp>
#endif

LibraryTest::LibraryTest()
{

}

void LibraryTest::testBoost() const noexcept
{
  //!Boost Library
#ifdef USE_BOOST
  std::cout << "Boost version " << BOOST_VERSION << std::endl;
  std::cout << "Boost Lib Clock Test\n";
  boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
  for ( long i = 0; i < 10000000; ++i )
    std::sqrt( 123.456L ); // burn some time
  boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
  std::cout << "took " << sec.count() << " seconds\n";
#else
  std::cout << "Boost Library is not available.\n";
#endif

}
```

- Language Test
```cpp
#ifdef USE_FEATURE_TEST
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
#else
  std::cout << "Test Feature is not available.\n";
#endif
```
- Config Test
```cpp

#include "config.hpp"
#include <iostream>

    std::cout << "========CONFIG TEST========" << std::endl;
    std::cout << "Project Name : "          << PROJECT_NAME << std::endl;
    std::cout << "Project Description : "   << PROJECT_DESCRIPTION << std::endl;
    std::cout << "Project Homepage Url : "  << PROJECT_HOMEPAGE_URL << std::endl;
    std::cout << "Project Language : "      << PROJECT_LANGUAGES << std::endl;
    std::cout << "Project Full Version : "  << PROJECT_VERSION_STRING << std::endl;
    std::cout << "Project Creator : "       << PROJECT_CREATOR << std::endl;
    std::cout << "Project License Type : "  << PROJECT_LICENSE_TYPE << std::endl;
    std::cout << "========CONFIG TEST========" << std::endl;
  
```
## If you want donate, Bitcoin address is here! <3
<img width="368" alt="Screenshot 2022-11-12 at 9 25 49 AM" src="https://user-images.githubusercontent.com/4066299/201459675-f3c0d09e-f308-4fa6-9be2-60a4bd81212e.png">

## TOOD
- Bug fixing.
- Add new exception handler.
- Add new features.
- Support new libraries.
- Tell me your opinion about which other items should be added.

## Contribution
- Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com
