//
// Created by ANDREW SMITH on 10/12/2022.
//

#ifndef AOC22_INSTRUCTION_H
#define AOC22_INSTRUCTION_H
#include <variant>
#include "AddX.h"
#include "Noop.h"

using Instruction = std::variant<AddX, Noop>;
#endif //AOC22_INSTRUCTION_H
