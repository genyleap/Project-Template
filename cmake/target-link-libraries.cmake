cmake_minimum_required(VERSION 3.20)
if(${CMAKE_VERSION} VERSION_LESS 3.20)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.20)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# ------ PROJECT INFO ------
include(project-info)
if(project-info)
  return()
endif()
set(project-info ON)

include(packages)
if(packages)
return()
endif()
set(packages ON)

if(USE_GOOGLE_TEST)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)
endif()

if(USE_CATCH2)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
endif()

if(USE_NONE_STL_JSON)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
endif()
