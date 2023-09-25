cmake_minimum_required(VERSION 3.23)
cmake_policy(SET CMP0048 NEW)

# ------ PROJECT INFO ------
# You can change "ProjectTemplate" with your project name.
set(PROJECT_NAME "PT" CACHE STRING "Project Name.")
set(PROJECT_TARGET ${PROJECT_NAME} CACHE STRING "Project Target Name.")
set(PROJECT_REAL_NAME "PT" CACHE STRING "Project Real Name.")

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 300)

#Your project creator.
set(PROJECT_CREATOR "Kambiz Asadzadeh" CACHE STRING "Creator of your project.")

#Your project creator.
set(PROJECT_ORGANIZATION "The Genyleap" CACHE STRING "Organization name.")

#Your project license type.
set(PROJECT_LICENSE_TYPE "MIT" CACHE STRING "Project License Type.")

set(PROJECT_VERSION_TYPE "final" CACHE STRING "Version type.")

#Use these keys [application, library]
set(PROJECT_USAGE_TYPE "application" CACHE STRING "Usage Type.")

#Use these keys [stl, qt, qtwidget, qtquick]
set(PROJECT_MAIN_TYPE "stl" CACHE STRING "Library System.")

set(DEVELOPER_BUNDLE_IDENTIFIER com.kambizasadzadeh.app.${PROJECT_NAME} CACHE STRING "Developer Bundle Identifier.")

#You can replace your project description with this string.
set(PROJECT_DESCRIPTION "A template for modern C++ projects with useful features for developing cross-platform projects." CACHE STRING "Project Description")

#Your project website address.
set(PROJECT_HOMEPAGE_URL "https://github.com/genyleap/Project-Template" CACHE STRING "Project URL.")
