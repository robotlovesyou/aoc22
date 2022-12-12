//
// Created by ANDREW SMITH on 12/12/2022.
//

#include "Map.h"

Map::Map(size_t width, size_t height): _width(width), _height(height) {
    _height_map = std::vector<unsigned short>(_height * _width);
}

void Map::set_height(const Coord &coord, unsigned short h) {
    _height_map[coord_to_offset(coord)] = h;

}

void Map::set_start(const Coord &coord) {
    _height_map[coord_to_offset(coord)] = 0;
    _start = {coord.x,coord.y};
}

void Map::set_end(const Coord &coord) {
    _height_map[coord_to_offset(coord)] = 25;
    _end = {coord.x, coord.y};
}

size_t Map::coord_to_offset(const Coord &coord) const {
    return _width * coord.y + coord.x;
}

unsigned short Map::height_at(const Coord &coord) {
    return _height_map[coord_to_offset(coord)];
}

const Coord &Map::start() {
    return _start;
}

const Coord &Map::end() {
    return _end;
}

size_t Map::height() const {
    return _height;
}

size_t Map::width() const {
    return _width;
}
