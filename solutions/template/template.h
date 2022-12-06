//
// Created by ANDREW SMITH on 06/12/2022.
//

#ifndef AOC22_TEMPLATE_H
#define AOC22_TEMPLATE_H
#include <string>
#include <fstream>
#include <sstream>

std::string dayXX(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;

    while(std::getline(infile, line)) {
        std::istringstream iss(line);
    }

    std::ostringstream oss;
    oss << "part1: " << "part1" << " part2: " << "part2";
    return oss.str();
}
#endif //AOC22_TEMPLATE_H
