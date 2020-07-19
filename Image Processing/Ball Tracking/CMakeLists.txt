cmake_minimum_required(VERSION 3.1.10)

project(ball_tracking)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_compile_options(-Wpedantic -Werror -Wall -Wextra --pedantic-errors -o3)

add_executable(ball_tracking main.cpp)
target_link_libraries(ball_tracking ${OpenCV_LIBS})