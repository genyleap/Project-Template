#Package Info.
set(QT_NAME "Qt")
set(QT_DESCRIPTION "A modern cross-platform graphical user interfaces framework.")

#Pakcage option.
option(USE_QT ${QT_DESCRIPTION} FALSE)
if (USE_QT)
  add_definitions(-DUSE_QT)
endif()

#TODO for non-qt creator base projects.
