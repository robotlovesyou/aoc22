//
// Created by ANDREW SMITH on 05/12/2022.
//

#ifndef AOC22_DAY05_H
#define AOC22_DAY05_H

#include <string>
#include <fstream>
#include <sstream>
#include <queue>

bool read_stack(std::string &line, int ord, char &entry) {
    int index = ord * 4 + 1;
    if (line.length() <= index) {
        return false;
    }
    entry = line[index];
    return entry != ' ';
}

struct Command {
public:
    int count;
    int from;
    int to;
};

Command read_command(std::string &line) {
    std::istringstream iss(line);
    std::string word;
    Command cmd{};
    iss >> word;
    iss >> cmd.count;
    iss >> word;
    iss >> cmd.from;
    iss >> word;
    iss >> cmd.to;
    return cmd;
}


std::string day05(std::string &filename) {
    std::ifstream infile(filename);
    std::string line;

    std::deque<char> default_q;
    std::vector<std::deque<char>> queues(9, default_q);
    int count = 0;
    while(std::getline(infile, line)) {
        count += 1;
        if (count > 8) {
            break;
        }
        for(int i = 0; i < 9; i++) {
            char entry = ' ';
            if (read_stack(line, i, entry)) {
                queues[i].emplace_back(entry);
            }
        }
    }
    std::getline(infile, line);
// PART 1 stacking
//    while(std::getline(infile, line)) {
//        Command cmd = read_command(line);
//        for(int i = 0; i < cmd.count; i++) {
//            char entry = queues[cmd.from-1].front();
//            queues[cmd.from-1].pop_front();
//            queues[cmd.to-1].emplace_front(entry);
//        }
//    }
    // PART2 stacking
    while(std::getline(infile, line)) {
        Command cmd = read_command(line);
        std::deque<char> pick_pile;
        // pick
        for(int i = 0; i < cmd.count; i++) {
            pick_pile.emplace_front(queues[cmd.from-1].front());
            queues[cmd.from-1].pop_front();
        }
        // drop
        while(!pick_pile.empty()) {
            queues[cmd.to-1].emplace_front(pick_pile.front());
            pick_pile.pop_front();
        }
    }

    std::string result;
    for (auto q: queues) {
        char front = q.front();
        result.push_back(front);
    }

    std::ostringstream oss;
    oss << "result: " << result;
    return oss.str();
}

#endif //AOC22_DAY05_H
