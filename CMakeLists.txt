cmake_minimum_required(VERSION 3.20.0)
project(Race)

add_executable(main main.cpp)
add_subdirectory(engine)
target_include_directories(main PUBLIC scenes)
target_link_libraries(main sfml-window sfml-graphics sfml-system jsoncpp)
set(CMAKE_DEBUG_POSTFIX d)