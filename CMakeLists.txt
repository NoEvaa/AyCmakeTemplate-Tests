cmake_minimum_required(VERSION 3.15)

# ==================================================
# Project

project(
    AyTests
    VERSION 0.1.0
    LANGUAGES CXX
)

# ==================================================

# Project options
include(cmake/Options.cmake)
# Utils 
include(cmake/Utils.cmake)
# Init cmake environment
include(cmake/Init.cmake)

# ==================================================
# Project development environment 

if(${PROJECT_NAME}_IS_MAIN)
    # Tests
    if(${PROJECT_NAME}_ENABLE_TESTS)
        enable_testing()
        add_subdirectory(tests)
    endif()
endif()

