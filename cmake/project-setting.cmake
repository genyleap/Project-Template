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

option(GUI_APPLICATION    "Include User Interface"  FALSE)
if (GUI_APPLICATION)
  add_definitions(-DGUI_APPLICATION)
endif()

option(FORCE_UPGRADED_LIBS    "Force to update latest version of dependencies from repositories."  FALSE)
if (FORCE_UPGRADED_LIBS)
  add_definitions(-DFORCE_UPGRADED_LIBS)
endif()

option(USE_CUSTOM_ENGINE    "Include your own engine"  FALSE)
if (USE_CUSTOM_ENGINE)
  add_definitions(-DUSE_CUSTOM_ENGINE)
endif()

set(ENGINE_CODE_NAME "Cell" CACHE STRING "Your own engine code name as string.")
if (USE_CUSTOM_ENGINE)
  add_definitions(-DENGINE_CODE_NAME)
endif()
