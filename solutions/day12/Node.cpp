//
// Created by ANDREW SMITH on 12/12/2022.
//

#include "Node.h"

Node::Node(Coord icord, size_t icost, size_t ih_cost): coord(icord), cost(icost), h_cost(ih_cost) {}

bool operator<(const Node &l, const Node &r) {
    return l.total_cost() < r.total_cost();
}

bool operator>(const Node &l, const Node &r) {
    return l.total_cost() > r.total_cost();
}

size_t Node::total_cost() const {
    return cost + h_cost;
}

