cmake_minimum_required(VERSION 3.23)
cmake_policy(SET CMP0048 NEW)

set(THIRD_PARTY "third-party" CACHE STRING "3rdparty folder for project dependencies. [Don't change this variable.]")


option(USE_LATEST_STANDARD    "Include latest standard of C++"  TRUE)
if (USE_LATEST_STANDARD)
  add_definitions(-DUSE_LATEST_STANDARD)
endif()

#option(USE_QT    "Include Qt Framework"  FALSE)
#if (USE_QT)
#  add_definitions(-DUSE_QT)
#endif()

option(USE_QT5_FEATURES    "Include Qt5 Framework features"  FALSE)
if (USE_QT5_FEATURES)
  add_definitions(-DUSE_QT5_FEATURES)
endif()

option(USE_FULL_QT_FEATURES    "Include Full features of Qt Framework"  FALSE)
if (USE_FULL_QT_FEATURES)
  add_definitions(-USE_FULL_QT_FEATURES)
endif()


option(HAS_USER_INTERFACE    "Include GUI"  FALSE)
if (HAS_USER_INTERFACE)
  add_definitions(-DHAS_USER_INTERFACE)
endif()
