//
// Created by ANDREW SMITH on 12/12/2022.
//

#ifndef AOC22_MAP_H
#define AOC22_MAP_H
#import <vector>
#include "Coord.h"

class Map {
public:
    Map(size_t width, size_t height);
    void set_height(const Coord &coord, unsigned short h);
    void set_start(const Coord &coord);
    void set_end(const Coord &coord);
    unsigned short height_at(const Coord &coord);
    const Coord &start();
    const Coord &end();
    size_t height() const;
    size_t width() const;
private:
    size_t _height;
    size_t _width;
    Coord _start{0,0};
    Coord _end{0,0};
    std::vector<unsigned short> _height_map;
    [[nodiscard]] size_t coord_to_offset(const Coord &coord) const;

};


#endif //AOC22_MAP_H
