//
// Created by ANDREW SMITH on 11/12/2022.
//

#ifndef AOC22_DAY11_H
#define AOC22_DAY11_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include "Monkey.h"

long read_long(std::istream &is) {
    std::string num_str;
    char c = (char) is.peek();
    while (c >= '0' && c <= '9') {
        num_str.push_back(c);
        is.get();
        c = (char) is.peek();
    }
    return std::stol(num_str);
}

std::vector<long> parse_items_line(std::string &line) {
    std::vector<long> items;
    std::istringstream iss(line);
    std::string ignore;
    iss >> ignore >> ignore;
    char c = (char) iss.peek();
    while (c != EOF) {
        if (c >= '0' && c <= '9') {
            items.push_back(read_long(iss));
        } else {
            // it's a comma or a space so just consume it
            iss.get();
        }
        c = (char) iss.peek();
    }
    return items;
}

std::pair<Operation, long> parse_operation_line(std::string &line) {
    char op_ch;
    long arg;
    std::string ignore;
    std::istringstream iss(line);
    iss >> ignore >> ignore >> ignore >> ignore >> op_ch;
    // consume the ' '
    iss.get();
    if (iss.peek() == 'o') {
        return {Operation::kSquare, 0};
    } else {
        iss >> arg;
        Operation op = op_ch == '*' ? Operation::kMult : Operation::kAdd;
        return {op, arg};
    }
}

long parse_test_line(std::string &line) {
    long div;
    std::string ignore;
    std::istringstream iss(line);
    iss >> ignore >> ignore >> ignore >> div;
    return div;
}

size_t parse_true_false_line(std::string &line) {
    size_t idx;
    std::string ignore;
    std::istringstream iss(line);
    iss >> ignore >> ignore >> ignore >> ignore >> ignore >> idx;
    return idx;
}


UMonkey parse_monkey(std::istream &input) {
    std::string line;

    // read and ignore the ID line
    std::getline(input, line);
    // read the items line
    std::getline(input, line);
    std::vector<long> items = parse_items_line(line);
    // read the operation line
    std::getline(input, line);
    std::pair<Operation, long> op_arg = parse_operation_line(line);
    // read the test line
    std::getline(input, line);
    long div = parse_test_line(line);
    // read the true line
    std::getline(input, line);
    size_t if_true = parse_true_false_line(line);
    // read the false line
    std::getline(input, line);
    size_t if_false = parse_true_false_line(line);
    // consume the blank line
    std::getline(input, line);
    // construct and return the monkey
    UMonkey m = std::make_unique<Monkey>(
            op_arg.first,
            std::make_unique<BigInt>(op_arg.second),
            std::make_unique<BigInt>(div),
            if_true,
            if_false
    );
    for (auto itm: items) {
        m->add_item(std::move(std::make_unique<BigInt>(itm)));
    }
    return m;
}

void round(std::vector<UMonkey> &monkeys, bool worried, BigInt *test_prod) {
    for(auto &m: monkeys) {
        while(m->has_items()) {
            UBigInt new_value = m->operate(worried, test_prod);
            if(m->test(new_value.get())) {
                monkeys[m->if_true()]->add_item(std::move(new_value));
            } else {
                monkeys[m->if_false()]->add_item(std::move(new_value));
            }
            m->throw_item();
        }
    }
//    for(size_t i = 0; i < monkeys.size(); i++) {
//        std::cout << "Monkey " << i << ":";
//        monkeys[i]->inspect();
//    }
}

unsigned long mult_inspections(std::vector<UMonkey> &monkeys) {
    std::vector<size_t> ops;
    for (auto &m: monkeys) {
        ops.push_back(m->operations());
    }
    std::sort(ops.begin(), ops.end());
    std::reverse(ops.begin(), ops.end());
    return ops[0] * ops[1];
}

std::vector<UMonkey> read_monkeys(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;
    std::vector<UMonkey> monkeys;

    while (infile.peek() != EOF) {
        monkeys.emplace_back(std::move(parse_monkey(infile)));
    }
    return monkeys;
}

UBigInt divisor_product(std::vector<UMonkey> &monkeys) {
    UBigInt last = std::make_unique<BigInt>(1);
    for (auto &m: monkeys) {
        UBigInt product = std::make_unique<BigInt>(0);
        product->Mult(last.get(), m->divisor());
        last = std::move(product);
    }
    return last;
}

std::string day11(std::string &filename) {
    std::vector<UMonkey> monkeys_1 = read_monkeys(filename);
    UBigInt test_prod = divisor_product(monkeys_1);
    for(uint i = 0; i < 20; i++) {
        round(monkeys_1, true, test_prod.get());
    }

    std::vector<UMonkey> monkeys_2 = read_monkeys(filename);
    for(uint i = 0; i < 10000; i++) {
        round(monkeys_2, false, test_prod.get());
    }

    std::ostringstream oss;
    oss << "part1: " << mult_inspections(monkeys_1) << " part2: " << mult_inspections(monkeys_2);
    return oss.str();
}

#endif //AOC22_DAY11_H
