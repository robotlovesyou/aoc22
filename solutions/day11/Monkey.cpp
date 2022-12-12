//
// Created by ANDREW SMITH on 11/12/2022.
//

#include "Monkey.h"


Monkey::Monkey(Operation op, UBigInt arg, UBigInt divisor, size_t true_target, size_t false_target) : _op(op),
                                                                                                _arg(std::move(arg)),
                                                                                                _divisor(std::move(divisor)),
                                                                                                _true_target(true_target),
                                                                                                _false_target(false_target) {}

void Monkey::add_item(UBigInt item) {
    _items.emplace_back(std::move(item));
}

void Monkey::throw_item() {
    _items.pop_front();
}

UBigInt Monkey::operate(bool worried, BigInt *test_prod) {
//    std::cout << "value:";
//    _items.front().get()->inspect();
//    std::cout << "arg:";
//    _arg->inspect();
    UBigInt result = std::make_unique<BigInt>(0);
    if (_op == Operation::kMult) {
        result->Mult(_items.front().get(), _arg.get());
    } else  if (_op == Operation::kAdd) {
        result->Add(_items.front().get(), _arg.get());
    } else {
        result->Mult(_items.front().get(), _items.front().get());
    }
//    std::cout << "result:";
//    result->inspect();
//    std::cout << std::endl;
    _operations++;
    if (worried) {
        UBigInt divided = std::make_unique<BigInt>(0);
        UBigInt divisor = std::make_unique<BigInt>(3);
        divided->Div(result.get(), divisor.get());
        return divided;
    } else {
        // something clever?
        UBigInt rem = std::make_unique<BigInt>(0);
        rem->Rem(result.get(), test_prod);
        return rem;
    }


}

bool Monkey::test(BigInt *target) {
    return target->DividesInto(_divisor.get());
}

size_t Monkey::if_true() const {
    return _true_target;
}

size_t Monkey::if_false() const {
    return _false_target;
}

bool Monkey::has_items() {
    return !_items.empty();
}

size_t Monkey::operations() const {
    return _operations;
}

void Monkey::inspect() {
    for (auto & _item : _items) {
        _item->inspect();
        std::cout << " ";
    }
    std::cout << std::endl;
}

BigInt *Monkey::divisor() {
    return _divisor.get();
}
