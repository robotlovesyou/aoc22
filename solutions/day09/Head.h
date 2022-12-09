//
// Created by ANDREW SMITH on 09/12/2022.
//

#ifndef AOC22_HEAD_H
#define AOC22_HEAD_H

#include <vector>
#include "defs.h"
#include "Tail.h"

class Head {
public:
    explicit Head(size_t tail_len);
    void move(char direction, int amount);
    size_t tail_visited();


private:
    void head_moved();
    std::vector<Tail> _tail;
    coord _position;
};


#endif //AOC22_HEAD_H
