//
// Created by ANDREW SMITH on 01/12/2022.
//

#ifndef AOC22_DAY01_H
#define AOC22_DAY01_H
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

std::string day01(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;

    std::priority_queue<long> sums;
    long sum = 0;
    while(std::getline(infile, line)) {
        long n;
        std::istringstream iss(line);
        if(iss >> n) {
            sum += n;
        } else {
            sums.push(sum);
            sum = 0;
        }
    }

    long part1 = sums.top();
    sums.pop();
    long part2 = part1 + sums.top();
    sums.pop();
    part2 += sums.top();

    std::ostringstream oss;
    oss << "part1: " << part1 << " part2: " << part2;
    return oss.str();
}

#endif //AOC22_DAY01_H



