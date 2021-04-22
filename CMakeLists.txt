cmake_minimum_required(VERSION 3.20)

if("${CMAKE_PROJECT_NAME}" STREQUAL "")
    project(cpp_compatibility LANGUAGES C CXX ASM)
endif()

add_library(cpp_compatibility INTERFACE)

target_include_directories(cpp_compatibility SYSTEM BEFORE INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
