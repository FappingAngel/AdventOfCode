cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdventOfCode
        Solutions/2015_d2.cpp
        Solutions/2015_d3.cpp
        Solutions/2015_d5.cpp
        Solutions/2015_d6.cpp
        Solutions/2016_d1.cpp
    main.cpp
        headers/2015_d3.h
        headers/2015_d5.h
        headers/2015_d6.h
        headers/2015_d7.h
        headers/2016_d1.h
        headers/2015_d2.h)
