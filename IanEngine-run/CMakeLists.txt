cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_COMPILER "/MinGW/mingw64/bin/g++.exe")
set (CMAKE_CXX_STANDARD 20)

project(main)

add_executable(main main/main.cpp)

find_package(IanEngine REQUIRED)

target_link_libraries(main IanEngine)