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

//ThirdParty libs
#include "examples/thirdpartytest.hpp"

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
  thirdPartyTest.testCtre();

  return 0;
}

#endif
