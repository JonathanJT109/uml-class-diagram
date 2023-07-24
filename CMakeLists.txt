cmake_minimum_required(VERSION 3.25)

project(umlClassDiagram VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/../bin/")

add_executable(umlClassDiagram src/main.cpp include/lexer.cpp include/token.cpp)

include_directories(include)
