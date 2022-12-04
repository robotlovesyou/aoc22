//
// Created by ANDREW SMITH on 04/12/2022.
//

#ifndef AOC22_DAY04_H
#define AOC22_DAY04_H

#include <iostream>
#include <queue>

std::string day04(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;

    long contained = 0;
    long overlapped = 0;

    while(std::getline(infile, line)) {
        int a_low = 0;
        int a_high = 0;
        int b_low = 0;
        int b_high = 0;

        std::istringstream iss(line);
        iss >> a_low;
        iss.get();
        iss >> a_high;
        iss.get();
        iss >> b_low;
        iss.get();
        iss >> b_high;

        if ((b_low >= a_low && b_high <= a_high) || (a_low >= b_low && a_high <= b_high)) {
            contained ++;
        }
        if ((b_low >= a_low && b_low <= a_high) || (a_low >= b_low && a_low <= b_high)) {
            overlapped++;
        }

    }



    std::ostringstream oss;
    oss << "part1: " << contained << " part2: " << overlapped;
    return oss.str();
}

#endif //AOC22_DAY04_H
