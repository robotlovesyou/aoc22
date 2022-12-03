//
// Created by ANDREW SMITH on 03/12/2022.
//

#ifndef AOC22_DAY03_H
#define AOC22_DAY03_H
#include <iostream>
#include <algorithm>
#include <vector>
int score(char c) {
    int i = (int)(unsigned char)c;
    if (i > 96) {
        return i - 96;
    } else {
        return i - 38;
    }
}

std::string day03(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    long sum = 0;
    long sum_2 = 0;
    std::vector<std::vector<std::string>> groups;
    auto *group = new std::vector<std::string>();

    while(std::getline(infile, line)) {
        if (group->size() == 3) {
            groups.emplace_back(*group);
            group = new std::vector<std::string>();
        }
        std::string long_lived_line = line;
        std::sort(long_lived_line.begin(), long_lived_line.end());
        auto last = std::unique(long_lived_line.begin(), long_lived_line.end());
        long_lived_line.erase(last, long_lived_line.end());
        group->emplace_back(long_lived_line);

        std::set<char> items;
        std::string compartment_1 = line.substr(0, line.length()/2);
        std::string compartment_2 = line.substr(line.length()/2, line.length());
        for(char c : compartment_1) {
            items.insert(c);
        }

        char dup;
        for(char c: compartment_2) {
            if (items.find(c) != items.end()) {
                dup = c;
                goto found;
            }
        }
        found:
        sum += score(dup);
    }
    groups.emplace_back(*group);

    for(const auto& g: groups) {
        std::map<char, int> items;
        int ln = 0;
        for(const auto& l: g) {
            ln += 1;
            for(auto c: l) {
                auto item = items.find(c);
                if (item != items.end()) {
                    item->second += 1;
                } else {
                    items.emplace(c, 1);
                }
            }
        }

        for(auto item: items) {
            if (item.second == 3) {
                sum_2 += score(item.first);
                break;
            }
        }
    }

    std::ostringstream oss;
    oss << "part1: " << sum << " part2: " << sum_2;
    return oss.str();
}
#endif //AOC22_DAY03_H
