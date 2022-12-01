cmake_minimum_required(VERSION 3.23)
project(aoc22)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/thirdparty)

add_executable(
        aoc22
        include/thirdparty/cli11/cli11.hpp
        main.cpp
        include/solutions/day01/day01.h)
