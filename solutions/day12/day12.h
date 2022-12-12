//
// Created by ANDREW SMITH on 12/12/2022.
//

#ifndef AOC22_DAY12_H
#define AOC22_DAY12_H
#include <string>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "Pathfinder.h"

std::unique_ptr<Map> read_map(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    std::vector<std::string> lines;
    char a = 97;

    while(std::getline(infile, line)) {
        lines.emplace_back(line);
    }
    auto map = std::make_unique<Map>(lines[0].size(), lines.size());
    for(size_t y = 0; y < lines.size(); y++) {
        for(size_t x = 0; x < lines[0].size(); x++) {
            char c = lines[y][x];
            switch(c) {
                case 'S':
                    map->set_start(Coord{x,y});
                    break;
                case 'E':
                    map->set_end(Coord{x, y});
                    break;
                default:
                    map->set_height(Coord{x, y}, c-a);
                    break;
            }
        }
    }
    return map;
}

size_t cheapest_possible(std::string &filename) {
    size_t cheapest = ULLONG_MAX;
    auto temp_map = read_map(filename);
    size_t width = temp_map->width();
    size_t height = temp_map->height();
    for(size_t y = 0; y < height; y++) {
        for(size_t x = 0; x < width; x++) {
            auto map = read_map(filename);
            Coord c{x, y};
            if(map->height_at(c) == 0) {
                map->set_start(c);
            } else {
                continue;
            }
            Pathfinder p(std::move(map));
            size_t cost = p.cheapest_path();
            if (cost < cheapest) {
                cheapest = cost;
            }
        }
    }
    return cheapest;
}

std::string day12(std::string &filename) {
    auto map = read_map(filename);
    Pathfinder p(std::move(map));
    std::ostringstream oss;
    oss << "part1: " << p.cheapest_path() << " part2: " << cheapest_possible(filename);
    return oss.str();
}
#endif //AOC22_DAY12_H
