//
// Created by ANDREW SMITH on 08/12/2022.
//

#ifndef AOC22_DAY08_H
#define AOC22_DAY08_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

void add_row_to_visible(std::vector<unsigned short> const &row, size_t y, std::set<std::pair<size_t, size_t>> &visible) {
    for(size_t x = 0; x < row.size(); x++) {
        visible.emplace(std::pair<size_t, size_t>(x, y));
    }
}

void add_ends_to_visible(std::vector<unsigned short> const &row, size_t y, std::set<std::pair<size_t, size_t>> &visible) {
    visible.emplace(std::pair<size_t, size_t>(0, y));
    visible.emplace(std::pair<size_t, size_t>(row.size()-1, y));
}

unsigned long count_visible(std::vector<std::vector<unsigned short>> const &trees) {
    std::set<std::pair<size_t, size_t>> visible;

    // place the edge trees into the map.
    add_row_to_visible(trees[0], 0, visible);
    add_row_to_visible(trees[trees.size()-1], trees.size()-1, visible);
    for(size_t y = 1; y < trees.size() -1; y++) {
        add_ends_to_visible(trees[y], y, visible);
    }


    // rows
    for(size_t y = 1; y < trees.size() -1; y++) {
        auto &row = trees[y];
        unsigned short tallest_l = row[0];
        unsigned short tallest_r = row[row.size()-1];
        // rows from left
        for(size_t x = 1; x < row.size() -1; x++) {
            if (row[x] > tallest_l) {
                visible.emplace(std::pair<size_t, size_t>(x, y));
                tallest_l = row[x];
            }
        }
        // rows from right
        for(size_t x = row.size() -2; x > 0; x--) {
            if(row[x] > tallest_r) {
                visible.emplace(std::pair<size_t, size_t>(x, y));
                tallest_r = row[x];
            }
        }
    }

    // columns from top
    // columns from bottom
    for(size_t x = 1; x < trees[0].size()-1; x++) {
        unsigned short tallest_t = trees[0][x];
        unsigned short tallest_b = trees[trees.size()-1][x];
        for(size_t y = 1; y < trees.size()-1; y++) {
            if (trees[y][x] > tallest_t) {
                visible.emplace(std::pair<size_t, size_t>(x, y));
                tallest_t = trees[y][x];
            }
        }
        for(size_t y = trees.size() -2; y > 0; y--) {
            if (trees[y][x] > tallest_b) {
                visible.emplace(std::pair<size_t, size_t>(x, y));
                tallest_b = trees[y][x];
            }
        }
    }

    return visible.size();
}

unsigned long best_view(std::vector<std::vector<unsigned short>> &trees) {
    unsigned long best = 0;
    for(size_t x = 0; x < trees[0].size(); x++) {
        for(size_t y = 0; y < trees.size(); y++) {
            unsigned short current_height = trees[y][x];
            unsigned long up = 0, down = 0, left = 0, right = 0;
            // up
            for(int uy = (int)y-1; uy >= 0; uy--) {
                up +=1;
                if (trees[(size_t)uy][x] >= current_height) {
                    break;
                }
            }
            // down
            for(int dy = (int)y+1; dy < trees.size(); dy++) {
                down += 1;
                if(trees[(size_t)dy][x] >= current_height) {
                    break;
                }
            }
            // left
            for(int lx = (int)x-1; lx >= 0; lx --) {
                left += 1;
                if(trees[y][(size_t)lx] >= current_height) {
                    break;
                }
            }
            // right
            for(int rx = (int)x+1; rx < trees[0].size(); rx++) {
                right += 1;
                if(trees[y][(size_t)rx] >= current_height) {
                    break;
                }
            }
            unsigned long current = up * down * left * right;
            if (current > best) {
                best = current;
            }
        }
    }
    return best;
}

std::string day08(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    std::vector<std::vector<unsigned short>> trees;

    while(std::getline(infile, line)) {
        std::vector<unsigned short> row;
        std::istringstream iss(line);
        char c;
        while(iss.get(c)) {
            row.emplace_back(c-48);
        }
        trees.emplace_back(std::move(row));
    }

    std::ostringstream oss;
    oss << "part1: " << count_visible(trees) << " part2: " << best_view(trees);
    return oss.str();
}

#endif //AOC22_DAY08_H
