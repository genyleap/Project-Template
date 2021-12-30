#include "examples/platformtest.hpp"
#include "common.hpp"
#include <iostream>

using namespace std;

PlatformTest::PlatformTest()
{

}

void PlatformTest::getPlatformInfo() const noexcept
{
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
}
