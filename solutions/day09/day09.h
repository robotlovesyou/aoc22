//
// Created by ANDREW SMITH on 09/12/2022.
//

#ifndef AOC22_DAY09_H
#define AOC22_DAY09_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Tail.h"
#include "Head.h"

std::string day09(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    Head short_rope(1);
    Head long_rope(9);

    while(std::getline(infile, line)) {
        std::istringstream iss(line);
        char direction;
        int amount;
        iss >> direction >> amount;
        short_rope.move(direction, amount);
        long_rope.move(direction, amount);
    }

    std::ostringstream oss;
    oss << "part1: " << short_rope.tail_visited() << " part2: " << long_rope.tail_visited();
    return oss.str();
}
#endif //AOC22_DAY09_H
