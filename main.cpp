#include "cli11/CLI11.hpp"
#include <iostream>

int main(int argc, char** argv) {
    CLI::App app{"AOC 2022"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "The name of the input file");
    app.add_subcommand("1", "day 1")->final_callback([&filename](){
        std::cout << filename << std::endl;
    });
    app.require_subcommand(1);

    CLI11_PARSE(app, argc, argv);
    return 0;
}
