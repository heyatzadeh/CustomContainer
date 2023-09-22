cmake_minimum_required(VERSION 3.26)
project(CustomContainer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sourceFiles ./*.cpp Catch/catch_amalgamated.cpp)

include_directories(Catch)

add_executable(CustomContainer ${sourceFiles})
