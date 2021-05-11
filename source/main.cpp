#include <iostream>
#include "utilities/featuretest.hpp"

//!Boost Library
#ifdef USE_BOOST
#include <boost/chrono.hpp>
void testBoost() {
  boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
  for ( long i = 0; i < 10000000; ++i )
    std::sqrt( 123.456L ); // burn some time
  boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
  std::cout << "took " << sec.count() << " seconds\n";
}

#endif
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

#ifdef USE_BOOST
  testBoost();
#endif
  return 0;
}
