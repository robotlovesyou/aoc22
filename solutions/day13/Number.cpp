//
// Created by ANDREW SMITH on 13/12/2022.
//

#include "Number.h"

Number::Number(int n): _n(n) {}

Types Number::type() {
    return Types::kNumber;
}