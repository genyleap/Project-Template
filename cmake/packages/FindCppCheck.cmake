#Package Info.
set(CPPCHECK_NAME "CppCheck")
set(CPPCHECK_DESCRIPTION "Static analysis of C/C++ code.")

#Pakcage option.
option(USE_CPP_CHECK ${CPPCHECK_DESCRIPTION} FALSE)
if (USE_CPP_CHECK)
    add_definitions(-DUSE_CPP_CHECK)
endif()

if(USE_CPP_CHECK)
    externalproject_add(${CPPCHECK_NAME}
        GIT_REPOSITORY "https://github.com/danmar/cppcheck.git"
        GIT_TAG main
        INSTALL_DIR "${CMAKE_BINARY_DIR}/install/${CPPCHECK_NAME}"
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${CPPCHECK_NAME}
        CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY}/${CPPCHECK_NAME}
        UPDATE_COMMAND ""
        )
endif()
if(NOT CPPCHECK_FOUND)
    return()
endif()
