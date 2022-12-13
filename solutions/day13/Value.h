//
// Created by ANDREW SMITH on 13/12/2022.
//

#ifndef AOC22_VALUE_H
#define AOC22_VALUE_H

#include "Types.h"


class Value {
public:
    virtual Types type() = 0;
    virtual ~Value() {};
};


#endif //AOC22_VALUE_H
