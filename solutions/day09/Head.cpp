//
// Created by ANDREW SMITH on 09/12/2022.
//

#include <stdexcept>
#include "Head.h"

Head::Head(size_t tail_len) {
    _position = coord{0,0};
    for(size_t i = 0; i < tail_len; i++) {
        _tail.emplace_back(Tail());
    }
}

void Head::move(char direction, int amount) {
    vec change;
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
        head_moved();
    }
}

void Head::head_moved() {
    coord current = _position;
    for(auto &t: _tail) {
        coord new_p = t.head_moved(current);
        if (new_p == current) {
            break;
        }
        current = new_p;
    }
}

size_t Head::tail_visited() {
    return _tail[_tail.size()-1].visit_count();
}
