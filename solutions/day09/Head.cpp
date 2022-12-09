//
// Created by ANDREW SMITH on 09/12/2022.
//

#include <stdexcept>
#include "Head.h"

Head::Head(Tail *tail): _tail(tail) {
    _position = coord{0,0};
}

void Head::move(char direction, int amount) {
    vec change{0,0};
    switch(direction) {
        case 'U':
            change = {0,1};
            break;
        case 'D':
            change = {0, -1};
            break;
        case 'L':
            change = {-1,0};
            break;
        case 'R':
            change = {1,0};
            break;
        default:
            throw std::runtime_error("bad direction");
    }
    for(int i = 0; i < amount; i++) {
        _position.first += change.first;
        _position.second += change.second;
        _tail->head_moved(_position);
    }
}

coord Head::position() {
    return _position;
}
