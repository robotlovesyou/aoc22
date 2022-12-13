//
// Created by ANDREW SMITH on 13/12/2022.
//

#ifndef AOC22_DAY13_H
#define AOC22_DAY13_H
#include <string>
#include <fstream>
#include <sstream>
#include "Parser.h"

std::vector<std::pair<std::unique_ptr<Value>, std::unique_ptr<Value>>> read_pairs(std::ifstream &infile) {
    std::vector<std::pair<std::unique_ptr<Value>, std::unique_ptr<Value>>> pairs;
    while(infile.peek() != EOF) {
        std::string left, right, ignore;
        std::getline(infile, left);
        std::getline(infile, right);
        std::getline(infile, ignore);
        pairs.emplace_back(std::move(parse(left, right)));
    }
    return pairs;
}

std::string day13(std::string &filename) {
    std::ifstream infile(filename);

    std::vector<std::pair<std::unique_ptr<Value>, std::unique_ptr<Value>>> pairs = read_pairs(infile);

    std::ostringstream oss;
    oss << "part1: " << "part1" << " part2: " << "part2";
    return oss.str();
}
#endif //AOC22_DAY13_H
