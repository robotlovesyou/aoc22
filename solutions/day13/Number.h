//
// Created by ANDREW SMITH on 13/12/2022.
//

#ifndef AOC22_NUMBER_H
#define AOC22_NUMBER_H


#include "Value.h"

class Number: public virtual Value{
public:
    explicit Number(int n);
    Types type() override;

private:
    int _n;
};


#endif //AOC22_NUMBER_H
