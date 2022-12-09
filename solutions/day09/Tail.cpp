//
// Created by ANDREW SMITH on 09/12/2022.
//

#include "Tail.h"
#include <iostream>

Tail::Tail(Tail *next): _next(next) {
    _position = coord{0,0};
    _visited = std::set<coord>();
    _visited.insert(coord(_position));
}

inline vec diff(coord a, coord b) {
    return vec{a.first - b.first, a.second - b.second};
}

inline bool touching(vec d) {
    return (d.first >= -1 && d.first <= 1) && (d.second >=-1 && d.second <= 1);
}

void Tail::head_moved(coord position) {
    vec d = diff(position, _position);
    if (touching(diff(_position, position))) {
//        std::cout << "x: " << _position.first << " y: " << _position.second << std::endl;
        return;
    }
    if (d.first != 0 && d.second != 0) {
        _position.first += abs(d.first)/d.first;
        _position.second += abs(d.second)/d.second;
    }
    else if (abs(d.first) > 1) {
        _position.first += abs(d.first)/d.first;
    } else {
        _position.second += abs(d.second)/d.second;
    }
//    std::cout << "x: " << _position.first << " y: " << _position.second << std::endl;
    _visited.insert(coord(_position));
    if(_next != nullptr) {
        _next->head_moved(_position);
    }

}

size_t Tail::visit_count() {
    if (_next == nullptr) {
        return _visited.size();
    }
    return _next->visit_count();
}

