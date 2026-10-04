cmake_minimum_required(VERSION 3.21)
project(rul VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(rul INTERFACE)
add_library(rul::rul ALIAS rul)
target_include_directories(rul INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(rul INTERFACE cxx_std_20)

# Developer-only settings; never leak into projects that consume rul.
if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

option(RUL_BUILD_TESTS "Build RUL tests" ${PROJECT_IS_TOP_LEVEL})
if(RUL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
