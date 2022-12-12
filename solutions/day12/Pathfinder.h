//
// Created by ANDREW SMITH on 12/12/2022.
//

#ifndef AOC22_PATHFINDER_H
#define AOC22_PATHFINDER_H
#include <memory>
#include <set>
#include <queue>
#include "Map.h"
#include "Node.h"

class Pathfinder {
public:
    explicit Pathfinder(std::unique_ptr<Map> map);
    size_t cheapest_path();
private:
    size_t heuristic(const Coord &coord);
    bool can_move(const std::function<bool(Coord)>& test, const std::function<Coord(Coord)>&pos, Coord start);
    bool can_move_up(const Coord &coord);
    bool can_move_down(const Coord &coord);
    bool can_move_left(const Coord &coord);
    bool can_move_right(const Coord &coord);
    void emplace_node(Coord at, size_t cost);
    std::priority_queue<Node, std::vector<Node>, std::greater<>> _pq{};
    std::set<Coord> _visited;
    std::unique_ptr<Map> _map;
};


#endif //AOC22_PATHFINDER_H
