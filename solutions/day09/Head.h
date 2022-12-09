//
// Created by ANDREW SMITH on 09/12/2022.
//

#ifndef AOC22_HEAD_H
#define AOC22_HEAD_H

#include "defs.h"
#include "Tail.h"

class Head {
public:
    explicit Head(Tail* tail);
    void move(char direction, int amount);
    coord position();


private:
    Tail *_tail;
    coord _position;
};


#endif //AOC22_HEAD_H
