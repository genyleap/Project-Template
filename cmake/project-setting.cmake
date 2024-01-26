# ------ ADDITIONAL OPTIONS ------

# Use the latest standard of C++
option(USE_LATEST_STANDARD "Include the latest standard of C++" ON)
if (USE_LATEST_STANDARD)
  add_definitions(-DUSE_LATEST_STANDARD)
endif()

# Include Qt5 Framework features
option(USE_QT5_FEATURES "Include Qt5 Framework features" OFF)
if (USE_QT5_FEATURES)
  add_definitions(-DUSE_QT5_FEATURES)
endif()

# Include full features of Qt Framework
option(USE_FULL_QT_FEATURES "Include full features of Qt Framework" OFF)
if (USE_FULL_QT_FEATURES)
  add_definitions(-DUSE_FULL_QT_FEATURES)
endif()

# Include User Interface
option(GUI_APPLICATION "Include User Interface" OFF)
if (GUI_APPLICATION)
  add_definitions(-DGUI_APPLICATION)
endif()

# Force to update to the latest version of dependencies from repositories
option(FORCE_UPGRADED_LIBS "Force to update to the latest version of dependencies from repositories" OFF)
if (FORCE_UPGRADED_LIBS)
  add_definitions(-DFORCE_UPGRADED_LIBS)
endif()

# Include your own engine
option(USE_CUSTOM_ENGINE "Include your own engine" OFF)
if (USE_CUSTOM_ENGINE)
  add_definitions(-DUSE_CUSTOM_ENGINE)
endif()

# Your own engine code name as a string
set(ENGINE_CODE_NAME "Cell" CACHE STRING "Your own engine code name as a string.")
if (USE_CUSTOM_ENGINE)
  add_definitions(-DENGINE_CODE_NAME)
endif()
