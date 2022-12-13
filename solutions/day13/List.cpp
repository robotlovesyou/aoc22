//
// Created by ANDREW SMITH on 13/12/2022.
//

#include "List.h"

List::List(std::vector<std::unique_ptr<Value>> contents): _contents(std::move(contents)) {}

Types List::type() {
    return Types::kList;
}
