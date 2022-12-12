//
// Created by ANDREW SMITH on 12/12/2022.
//

#ifndef AOC22_NODE_H
#define AOC22_NODE_H


#include "Coord.h"

struct Node {
public:
    Node(Coord icord, size_t icost, size_t ih_cost);
    friend bool operator<(const Node& l, const Node& r);
    friend bool operator>(const Node& l, const Node& r);
    size_t total_cost() const;
    Coord coord;
    size_t cost;
    size_t h_cost;
};


#endif //AOC22_NODE_H
