#include "platformtest.hpp"
#include "common.hpp"
#include <iostream>

using namespace std;

PlatformTest::PlatformTest()
{

}

void PlatformTest::getPlatformInfo() const noexcept
{
#if defined(PLATFORM_MAC)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_MAC << "\n";
#elif defined(PLATFORM_WINDOWS)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_WINDOWS << "\n";
#elif defined(PLATFORM_LINUX)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_LINUX << "\n";
#elif defined(PLATFORM_FREEBSD)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_FREEBSD << "\n";
#elif defined(PLATFORM_OPENBSD)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_OPENBSD << "\n";
#elif defined(PLATFORM_VXWORKS)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_VXWORKS << "\n";
#elif defined(PLATFORM_MOTOROLA)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_MOTOROLA << "\n";
#elif defined(PLATFORM_ULTRIX)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_ULTRIX << "\n";
#elif defined(PLATFORM_DOS)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_DOS << "\n";
#elif defined(PLATFORM_WINDOWS_PHONE)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_WINDOWS_PHONE << "\n";
#elif defined(PLATFORM_IOS_SIMULATOR)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_IOS_SIMULATOR << "\n";
#elif defined(PLATFORM_IOS)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_IOS << "\n";
#elif defined(PLATFORM_APPLE_TV)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_APPLE_TV << "\n";
#elif defined(PLATFORM_IWATCH)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_IWATCH << "\n";
#elif defined(PLATFORM_ANDROID)
    cout << "Device: " << PLATFORM_DEVICE << "\n";
    cout << "Type: " << PLATFORM_TYPE << "\n";
    cout << "Platform OS: " << PLATFORM_OS << "\n";
    cout << "Platform Architecture: " << PLATFORM_ARCH << "\n";
    cout << "OS Name: " << PLATFORM_ANDROID << "\n";
#endif
}
