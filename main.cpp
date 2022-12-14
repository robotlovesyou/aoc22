#include "cli11/CLI11.hpp"
#include "solutions/day01/day01.h"
#include "solutions/day02/day02.h"
#include "solutions/day03/day03.h"
#include "solutions/day04/day04.h"
#include "solutions/day05/day05.h"
#include "solutions/day06/day06.h"
#include "solutions/day07/day07.h"
#include "solutions/day08/day08.h"
#include "solutions/day09/day09.h"
#include "solutions/day10/day10.h"
#include "solutions/day11/day11.h"
#include "solutions/day12/day12.h"
#include "solutions/day13/day13.h"

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
    app.add_subcommand("5", "day 5")->final_callback([&filename](){
        std::cout << day05(filename) << std::endl;
    });
    app.add_subcommand("6", "day 6")->final_callback([&filename](){
        std::cout << day06(filename) << std::endl;
    });
    app.add_subcommand("7", "day 7")->final_callback([&filename](){
        std::cout << day07(filename) << std::endl;
    });
    app.add_subcommand("8", "day 8")->final_callback([&filename](){
        std::cout << day08(filename) << std::endl;
    });
    app.add_subcommand("9", "day 9")->final_callback([&filename](){
        std::cout << day09(filename) << std::endl;
    });
    app.add_subcommand("10", "day 10")->final_callback([&filename](){
        std::cout << day10(filename) << std::endl;
    });
    app.add_subcommand("11", "day 11")->final_callback([&filename](){
        std::cout << day11(filename) << std::endl;
    });
    app.add_subcommand("12", "day 12")->final_callback([&filename](){
        std::cout << day12(filename) << std::endl;
    });
    app.add_subcommand("13", "day 13")->final_callback([&filename](){
        std::cout << day13(filename) << std::endl;
    });

    app.require_subcommand(1);

    CLI11_PARSE(app, argc, argv);
    return 0;
}
