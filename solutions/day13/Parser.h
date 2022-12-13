//
// Created by ANDREW SMITH on 13/12/2022.
//

#ifndef AOC22_PARSER_H
#define AOC22_PARSER_H
#include <sstream>
#include "List.h"
#include "Number.h"

std::unique_ptr<Value> parse_list(std::istringstream &iss, bool is_contents);

std::unique_ptr<Value> parse_number(std::istringstream &iss) {
    std::string num_string;
    while(iss.peek() != ']') {
        if(iss.peek() >= '0' && iss.peek() <= '9') {
            num_string.push_back((char)iss.get());
        } else if (iss.peek() == ',') {
            //consume the comma and stop parsing
            iss.get();
            break;
        } else {
            throw std::runtime_error("bad character in stream parsing number");
        }
    }
    return std::make_unique<Number>(stol(num_string));
}

std::vector<std::unique_ptr<Value>> parse_list_contents(std::istringstream &iss) {
    std::vector<std::unique_ptr<Value>> contents;
    while(iss.peek() != ']') {
        if (iss.peek() >= '0' && iss.peek() <= '9') {
            contents.emplace_back(std::move(parse_number(iss)));
        } else if (iss.peek() == '[') {
            contents.emplace_back((std::move(parse_list(iss, true))));
        } else {
            throw std::runtime_error("bad character in stream parsing list contents");
        }
    }
    return contents;
}

std::unique_ptr<Value> parse_list(std::istringstream &iss, bool is_contents) {
    // consume the [
    iss.get();
    // parse the contents
    std::vector<std::unique_ptr<Value>> contents = parse_list_contents(iss);
    // consume the ]
    iss.get();
    // if this is a child list consume any following ','. This is really hacky and would allow badly formatted input but we will not get that here (hopefully)
    if (is_contents && iss.peek() == ',') {
        iss.get();
    }
    return std::make_unique<List>(std::move(contents));
}




std::pair<std::unique_ptr<Value>,std::unique_ptr<Value>> parse(std::string &left, std::string &right) {
    std::istringstream lss(left);
    std::istringstream rss(right);
    std::unique_ptr<Value> lv = parse_list(lss, false);
    std::unique_ptr<Value> rv = parse_list(rss, false);
    return {std::move(lv), std::move(rv)};
}

#endif //AOC22_PARSER_H
