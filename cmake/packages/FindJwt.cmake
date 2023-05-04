# Package Info.
set(JWT_NAME "Jwt")
set(JWT_DESCRIPTION "A header only library for creating and validating json web tokens in c++")

# Pakcage option.
option(USE_JWT ${JWT_DESCRIPTION} FALSE)
if (USE_JWT)
    add_definitions(-DUSE_JWT)
    # Define the repository URL and tag for the JWT libraries
    set(JWT_URL "https://github.com/Thalhammer/jwt-cpp.git")
if(FORCE_UPGRADED_LIBS)
    set(JWT_TAG "master")
else()
    set(JWT_TAG "v0.7.0-rc.0")
endif()
endif()

if(USE_JWT)
    set(FETCHCONTENT_QUIET off)
    get_filename_component(jwt_base "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${PLATFORM_FOLDER_NAME}/${JWT_NAME}"
        REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${jwt_base})
    FetchContent_Declare(
        jwt
        GIT_REPOSITORY      ${JWT_URL}
        GIT_TAG             ${JWT_TAG}
        GIT_PROGRESS   TRUE
        )
    # Check if population has already been performed
    FetchContent_GetProperties(jwt)
    string(TOLOWER "${JWT_NAME}" lcName)
    if(NOT ${lcName}_POPULATED)
        FetchContent_Populate(${lcName})
        include_directories(${${lcName}_SOURCE_DIR}/include)
    endif()
    FetchContent_MakeAvailable(jwt)
    list(APPEND LIB_MODULES ssl crypto)
endif()
if(NOT JWT_FOUND)
    return()
endif()
