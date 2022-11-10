#include "librarytest.hpp"
#include "../common.hpp"
#include <iostream>

#ifdef USE_BOOST
#include <boost/chrono.hpp>
#endif

LibraryTest::LibraryTest()
{

}

void LibraryTest::testBoost() const noexcept
{
std::cout << "========BOOST TEST========" << std::endl;
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
  std::cout << "========BOOST TEST========" << std::endl;
}
