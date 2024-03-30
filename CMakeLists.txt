cmake_minimum_required(VERSION 3.20.0)
project(SFMLTest)

add_subdirectory(penguin)
add_subdirectory(engine)
add_executable(main main.cpp)