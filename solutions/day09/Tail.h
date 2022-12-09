//
// Created by ANDREW SMITH on 09/12/2022.
//

#ifndef AOC22_TAIL_H
#define AOC22_TAIL_H
#include <set>
#include "defs.h"

class Tail {
public:
    Tail(Tail *next);
    void head_moved(coord position);
    size_t visit_count();
    ~Tail() {
        delete _next;
    }
    Tail(const Tail&other) = delete;
    Tail& operator=(const Tail &other) = delete;
private:
    Tail *_next;
    coord _position;
    std::set<coord> _visited;
};


#endif //AOC22_TAIL_H
