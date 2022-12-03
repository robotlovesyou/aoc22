//
// Created by ANDREW SMITH on 02/12/2022.
//

#ifndef AOC22_DAY02_H
#define AOC22_DAY02_H
#include <iostream>

std::string day02(std::string &filename) {
    const char THEIR_ROCK = 'A';
    const char THEIR_PAPER = 'B';
    const char THEIR_SCISSORS = 'C';
    const char MY_ROCK = 'X';
    const char MY_PAPER = 'Y';
    const char MY_SCISSORS = 'Z';
    const char MY_LOOSE = 'X';
    const char MY_DRAW = 'Y';
    const char MY_WIN = 'Z';

    std::ifstream infile(filename);
    std::string line;

    long score = 0;
    long score2 = 0;
    while(std::getline(infile, line)) {
        char theirs;
        char mine;
        std::istringstream iss(line);
        iss >> theirs >> mine;
        switch (theirs) {
            case THEIR_ROCK:
                switch (mine) {
                    case MY_ROCK:
                        score += 4;
                        break;
                    case MY_PAPER:
                        score += 8;
                        break;
                    case MY_SCISSORS:
                        score += 3;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            case THEIR_PAPER:
                switch (mine) {
                    case MY_ROCK:
                        score += 1;
                        break;
                    case MY_PAPER:
                        score += 5;
                        break;
                    case MY_SCISSORS:
                        score += 9;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            case THEIR_SCISSORS:
                switch (mine) {
                    case MY_ROCK:
                        score += 7;
                        break;
                    case MY_PAPER:
                        score += 2;
                        break;
                    case MY_SCISSORS:
                        score += 6;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            default:
                throw std::runtime_error("invalid their move");
        }

        switch (theirs) {
            case THEIR_ROCK:
                switch (mine) {
                    case MY_LOOSE:
                        score2 += 3;
                        break;
                    case MY_DRAW:
                        score2 += 4;
                        break;
                    case MY_WIN:
                        score2 += 8;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            case THEIR_PAPER:
                switch (mine) {
                    case MY_LOOSE:
                        score2 += 1;
                        break;
                    case MY_DRAW:
                        score2 += 5;
                        break;
                    case MY_WIN:
                        score2 += 9;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            case THEIR_SCISSORS:
                switch (mine) {
                    case MY_LOOSE:
                        score2 += 2;
                        break;
                    case MY_DRAW:
                        score2 += 6;
                        break;
                    case MY_WIN:
                        score2 += 7;
                        break;
                    default:
                        throw std::runtime_error("invalid my move");
                }
                break;
            default:
                throw std::runtime_error("invalid their move");
        }
    }

    std::ostringstream oss;

    oss << "part1: " << score << " part2: " << score2;
    return oss.str();
}

#endif //AOC22_DAY02_H
