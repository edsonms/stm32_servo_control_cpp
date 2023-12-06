cmake_minimum_required(VERSION 3.20)

project("stm32_servo_control_cpp" C CXX ASM)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the source directory to the current directory
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

include(cmake/st-project.cmake)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

add_executable(${PROJECT_NAME} Core/Src/servo.cpp)

add_st_target_properties(${PROJECT_NAME})