//
// Created by ANDREW SMITH on 12/12/2022.
//

#ifndef AOC22_COORD_H
#define AOC22_COORD_H


#include <cstddef>

struct Coord {
public:
    size_t x, y;
    Coord(size_t ix, size_t iy);
    friend bool operator==(const Coord &l, const Coord &r);
    friend bool operator<(const Coord &l, const Coord &r);
};


#endif //AOC22_COORD_H
