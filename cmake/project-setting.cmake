set(THIRD_PARTY "third-party" CACHE STRING "3rdparty folder for project dependencies. [Don't change this variable.]")

option(USE_LATEST_STANDARD    "Include latest standard of C++"  TRUE)
if (USE_LATEST_STANDARD)
  add_definitions(-DUSE_LATEST_STANDARD)
endif()

option(USE_QT5_FEATURES    "Include Qt5 Framework features"  FALSE)
if (USE_QT5_FEATURES)
  add_definitions(-DUSE_QT5_FEATURES)
endif()

option(USE_FULL_QT_FEATURES    "Include Full features of Qt Framework"  FALSE)
if (USE_FULL_QT_FEATURES)
  add_definitions(-USE_FULL_QT_FEATURES)
endif()

option(GUI_APPLICATION    "Include User Interface"  TRUE)
if (GUI_APPLICATION)
  add_definitions(-DGUI_APPLICATION)
endif()
