//
// Created by ANDREW SMITH on 13/12/2022.
//

#ifndef AOC22_LIST_H
#define AOC22_LIST_H

#include "Value.h"
#include <vector>

class List: public virtual Value {
public:
    Types type() override;
    explicit List(std::vector<std::unique_ptr<Value>> contents);
private:
    std::vector<std::unique_ptr<Value>> _contents;
};


#endif //AOC22_LIST_H
