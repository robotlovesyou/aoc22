cmake_minimum_required(VERSION 3.23)
project(aoc22)

set(CMAKE_CXX_STANDARD 17)

set(GMP_DIR "/usr/local/Cellar/gmp/6.2.1_1")
include_directories(include/thirdparty ${GMP_DIR}/include)
find_library(GMP_LIBRARY NAMES gmp libgmp PATHS "${GMP_DIR}")
add_executable(
        aoc22
        include/thirdparty/cli11/cli11.hpp
        main.cpp
        solutions/day01/day01.h solutions/day02/day02.h solutions/day03/day03.h solutions/day04/day04.h solutions/day05/day05.h solutions/day06/day06.h solutions/template/template.h solutions/day07/day07.h solutions/day07/day07.cpp solutions/day08/day08.h solutions/day09/Head.cpp solutions/day09/Head.h solutions/day09/Tail.cpp solutions/day09/Tail.h solutions/day09/day09.h solutions/day09/defs.h solutions/day10/day10.h solutions/day10/Noop.cpp solutions/day10/Noop.h solutions/day10/AddX.cpp solutions/day10/AddX.h solutions/day10/Instruction.h solutions/day11/day11.h solutions/day11/Monkey.cpp solutions/day11/Monkey.h solutions/day11/BigInt.cpp solutions/day11/BigInt.h solutions/day12/day12.h solutions/day12/Map.cpp solutions/day12/Map.h solutions/day12/Coord.cpp solutions/day12/Coord.h solutions/day12/Pathfinder.cpp solutions/day12/Pathfinder.h solutions/day12/Node.cpp solutions/day12/Node.h)
target_link_libraries(${PROJECT_NAME}
        "${GMP_DIR}/lib/libgmp.10.dylib"
        "${GMP_DIR}/lib/libgmp.a"
        "${GMP_DIR}/lib/libgmp.dylib"
        "${GMP_DIR}/lib/libgmpxx.4.dylib"
        "${GMP_DIR}/lib/libgmpxx.a")
