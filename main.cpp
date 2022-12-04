#include "cli11/CLI11.hpp"
#include <iostream>
#include "solutions/day01/day01.h"
#include "solutions/day02/day02.h"
#include "solutions/day03/day03.h"
#include "solutions/day04/day04.h"

int main(int argc, char** argv) {
    CLI::App app{"AOC 2022"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "The name of the input file");
    app.add_subcommand("1", "day 1")->final_callback([&filename](){
        std::cout << day01(filename) << std::endl;
    });
    app.add_subcommand("2", "day 2")->final_callback([&filename](){
        std::cout << day02(filename) << std::endl;
    });
    app.add_subcommand("3", "day 3")->final_callback([&filename](){
        std::cout << day03(filename) << std::endl;
    });

    app.add_subcommand("4", "day 4")->final_callback([&filename](){
        std::cout << day04(filename) << std::endl;
    });

    app.require_subcommand(1);

    CLI11_PARSE(app, argc, argv);
    return 0;
}
