# ==================================================
# Project

project(
    AyTest
    VERSION 0.1.0
    LANGUAGES CXX
)

# Module: namespace::name
set(MODULE_NAME aytest)
set(MODULE_NS ayin)

# ==================================================
# Module library

add_library(${MODULE_NAME} INTERFACE)
target_include_directories(${MODULE_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${MODULE_NS}::${MODULE_NAME} ALIAS ${MODULE_NAME})
message(STATUS "Build library `${MODULE_NS}::${MODULE_NAME}`")

