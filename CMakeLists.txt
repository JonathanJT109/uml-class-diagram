cmake_minimum_required(VERSION 3.10)

project(umlClassDiagram)

add_executable(umlClassDiagram main.cpp)

include_directories(include)

set(CMAKE_CXX_STANDARD "${CMAKE_CXX_STANDARD} -std=c++17 -Wall")
