cmake_minimum_required(VERSION 3.26)
project(AdventOfCode23)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode23 main.cpp
        EnginePart.cpp
        EnginePart.h
        Gear.cpp
        Gear.h
        Card.cpp
        Card.h
        ConversionMap.cpp
        ConversionMap.h
        Hand.cpp
        Hand.h
)


# Add the path to the directory containing the library's header files
include_directories(C:/Dev/Functions)

# Link your executable with the library
target_link_libraries(AdventOfCode23 PRIVATE C:/Dev/Functions/libFunctions.a)