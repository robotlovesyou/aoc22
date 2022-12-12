//
// Created by ANDREW SMITH on 11/12/2022.
//

#ifndef AOC22_MONKEY_H
#define AOC22_MONKEY_H
#include <queue>
#include <iostream>
#include "BigInt.h"

enum Operation {
    kAdd,
    kMult,
    kSquare
};



class Monkey {
public:
    Monkey(Operation op, UBigInt arg, UBigInt divisor, size_t true_target, size_t false_target);
    void add_item(UBigInt item);
    UBigInt operate(bool worried, BigInt *test_prod);
    BigInt *divisor();
    void throw_item();
    bool test(BigInt* target);
    bool has_items();
    [[nodiscard]] size_t if_true() const;
    [[nodiscard]] size_t if_false() const;
    [[nodiscard]] size_t operations() const;
    void inspect();
private:
    std::deque<UBigInt> _items;
    UBigInt _arg;
    UBigInt _divisor;
    Operation _op;
    size_t _true_target;
    size_t _false_target;
    size_t _operations{};
};

using UMonkey = std::unique_ptr<Monkey>;


#endif //AOC22_MONKEY_H
