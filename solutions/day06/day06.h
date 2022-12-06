//
// Created by ANDREW SMITH on 06/12/2022.
//

#ifndef AOC22_DAY06_H
#define AOC22_DAY06_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

bool check_unique(char c, long &bits) {
    c-=64;
    if (bits & (1 << c)) {
        return false;
    }
    bits = bits | (1 << c);
    return true;
}

bool check_buffer_unique(std::deque<char> &buffer, int len) {
    long bits = 0;
    for(int i = 0; i < len; i++) {
        if(!check_unique(buffer[i], bits)) {
            return false;
        }
    }
    return true;
}

int find_start(std::istream &input, int len) {
    char c;
    int position = 0;

    std::deque<char> buffer;
    while(input.get(c)) {
        position ++;
        buffer.push_front(c);
        if (buffer.size() == len) {
            if(check_buffer_unique(buffer, len)) {
                return position;
            }
            buffer.pop_back();
        }
    }
    return -1;
}

std::string day06(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    std::getline(infile, line);

    std::istringstream p1(line);
    int p = find_start(p1, 4);

    std::istringstream p2(line);
    int m = find_start(p2, 14);

    std::ostringstream oss;
    oss << "part1: " << p << " part2: " << m;
    return oss.str();
}

#endif //AOC22_DAY06_H
