//
// Created by ANDREW SMITH on 12/12/2022.
//

#include "Coord.h"

Coord::Coord(size_t ix, size_t iy): x(ix), y(iy) {}

bool operator==(const Coord &l, const Coord &r) {
    return l.x == r.x && l.y == r.y;
}

bool operator<(const Coord &l, const Coord &r) {
    return (l.y < r.y) || (l.y == r.y && l.x < r.x);
}
