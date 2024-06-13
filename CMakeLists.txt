cmake_minimum_required(VERSION 3.20.0)
project(Race)

link_libraries(sfml-window sfml-graphics sfml-system jsoncpp)
include_directories(doctest/doctest)

add_executable(main main.cpp)
add_executable(main.exe main.cpp)
target_include_directories(main PUBLIC scenes)
target_include_directories(main.exe PUBLIC scenes)

add_subdirectory(engine)

set(CMAKE_DEBUG_POSTFIX d)
