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
    Tail tail(nullptr);
    Head short_rope(&tail);
    Tail *next = nullptr;
    for(int i  = 0; i < 9; i++) {
        next = new Tail(next);
    }
    Head long_rope(next);

    while(std::getline(infile, line)) {
//        std::cout << line << std::endl << "====" << std::endl;
        std::istringstream iss(line);
        char direction;
        int amount;
        iss >> direction >> amount;
        short_rope.move(direction, amount);
        long_rope.move(direction, amount);
    }

    std::ostringstream oss;
    oss << "part1: " << tail.visit_count() << " part2: " << next->visit_count();
    delete next;
    return oss.str();
}
#endif //AOC22_DAY09_H
