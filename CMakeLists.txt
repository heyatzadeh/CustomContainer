cmake_minimum_required(VERSION 3.26)
project(CustomContainer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sourceFiles ./*.cpp)

add_executable(CustomContainer ${sourceFiles})
