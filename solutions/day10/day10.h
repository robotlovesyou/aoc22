//
// Created by ANDREW SMITH on 10/12/2022.
//

#ifndef AOC22_DAY10_H
#define AOC22_DAY10_H

#include <string>
#include <fstream>
#include <sstream>

#include "Instruction.h"

int sig_strength(std::vector<int> &history, int at) {
    return at * history[at - 1];
}

int sum_reg(std::vector<int> &history) {
    return sig_strength(history, 20) + sig_strength(history, 60) + sig_strength(history, 100) +
           sig_strength(history, 140) + sig_strength(history, 180) + sig_strength(history, 220);
}

std::string line(std::vector<int>&history, int start_cycle) {
    std::string l;
    for(int pixel = 0; pixel < 40; pixel++) {
        int x = history[start_cycle+pixel];
        if(pixel >= x-1 && pixel <= x+1) {
            l.push_back('#');
        } else {
            l.push_back('.');
        }
    }
    return l;
}

std::string frame(std::vector<int>&history) {
    std::ostringstream oss;
    oss << line(history, 0) << std::endl;
    oss << line(history, 40) << std::endl;
    oss << line(history, 80) << std::endl;
    oss << line(history, 120) << std::endl;
    oss << line(history, 160) << std::endl;
    oss << line(history, 200) << std::endl;
    return oss.str();
}

std::string day10(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    std::vector<Instruction> instructions;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (iss.peek() == 'n') {
            instructions.emplace_back(Noop());
        } else {
            std::string command;
            int value;
            iss >> command >> value;
            instructions.emplace_back(AddX(value));
        }
    }

    std::vector<int> reg_history{1};
    int v_reg = 1;
    for (auto &inst: instructions) {
        if (std::holds_alternative<Noop>(inst)) {
            reg_history.push_back(v_reg);
        } else {
            auto addx = std::get<AddX>(inst);
            reg_history.push_back(v_reg);
            v_reg += addx.value();
            reg_history.push_back(v_reg);
        }
    }

    std::ostringstream oss;
    oss << "part1: " << sum_reg(reg_history) << std::endl << std::endl << frame(reg_history);
    return oss.str();
}

#endif //AOC22_DAY10_H
