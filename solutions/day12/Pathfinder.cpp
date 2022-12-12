//
// Created by ANDREW SMITH on 12/12/2022.
//

#include "Pathfinder.h"
#include <iostream>

size_t Pathfinder::cheapest_path() {
    _pq.emplace(_map->start(), 0, heuristic(_map->start()));
    Node cheapest{Coord{0, 0}, 0, 0};
    while (!_pq.empty()) {
        // get cheapest node
        cheapest = Node(_pq.top());
        _pq.pop();
        // check if cheapest node is at the end
        if (cheapest.coord == _map->end()) {
            return cheapest.cost;
        }
        // enqueue reachable nodes
        size_t new_cost = cheapest.cost + 1;
        if (can_move_up(cheapest.coord)) {
            emplace_node(Coord{cheapest.coord.x, cheapest.coord.y - 1}, new_cost);
        }
        if (can_move_down(cheapest.coord)) {
            emplace_node(Coord{cheapest.coord.x, cheapest.coord.y + 1}, new_cost);
        }
        if (can_move_left(cheapest.coord)) {
            emplace_node(Coord{cheapest.coord.x - 1, cheapest.coord.y}, new_cost);
        }
        if (can_move_right(cheapest.coord)) {
            emplace_node(Coord{cheapest.coord.x + 1, cheapest.coord.y}, new_cost);
        }
    }
    return ULLONG_MAX;
}

size_t Pathfinder::heuristic(const Coord &coord) {
    return abs((long) _map->end().x - (long) coord.x) + abs((long) _map->end().y - (long) coord.y);
}

bool Pathfinder::can_move_right(const Coord &coord) {
    return can_move([this](Coord coord) { return coord.x < this->_map->width() - 1; },
                    [](Coord start) { return Coord{start.x + 1, start.y}; }, coord);
}

bool Pathfinder::can_move_left(const Coord &coord) {
    return can_move([this](Coord coord) { return coord.x > 0; },
                    [](Coord start) { return Coord{start.x - 1, start.y}; }, coord);
}

bool Pathfinder::can_move_down(const Coord &coord) {
    return can_move([this](Coord coord) { return coord.y < this->_map->height() - 1; },
                    [](Coord start) { return Coord{start.x, start.y + 1}; }, coord);
}

bool Pathfinder::can_move_up(const Coord &coord) {
    return can_move([this](Coord coord) { return coord.y > 0; },
                    [](Coord start) { return Coord{start.x, start.y - 1}; }, coord);
}

void Pathfinder::emplace_node(Coord at, size_t cost) {
    _visited.emplace(at);
    _pq.emplace(at, cost, heuristic(at));
}

Pathfinder::Pathfinder(std::unique_ptr<Map> map) : _map(std::move(map)) {}

bool Pathfinder::can_move(const std::function<bool(Coord)> &test, const std::function<Coord(Coord)> &pos, Coord start) {
    if (test(start)) {
        Coord n = pos(start);
        return (int) _map->height_at(n) - (int) _map->height_at(start) <= 1 && _visited.find(n) == _visited.end();
    }
    return false;
}
