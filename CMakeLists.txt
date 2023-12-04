cmake_minimum_required(VERSION 3.26)
project(AdventOfCode23)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode23 main.cpp
        EnginePart.cpp
        EnginePart.h
        Gear.cpp
        Gear.h)
