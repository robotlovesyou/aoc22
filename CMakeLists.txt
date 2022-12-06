cmake_minimum_required(VERSION 3.23)
project(aoc22)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/thirdparty)

add_executable(
        aoc22
        include/thirdparty/cli11/cli11.hpp
        main.cpp
        solutions/day01/day01.h solutions/day02/day02.h solutions/day03/day03.h solutions/day04/day04.h solutions/day05/day05.h solutions/day06/day06.h solutions/template/template.h)
