//
// Created by ANDREW SMITH on 07/12/2022.
//

#include "day07.h"

File::File(std::string name, long size): _name(std::move(name)), _size(size) {}

unsigned long File::size() {
    return _size;
}

Type File::type() {
    return Type::kFile;
}

std::string File::name() {
    return _name;
}

Directory::Directory(std::string name): _name(std::move(name)) {
}

unsigned long Directory::size() {
    unsigned long sum = 0;
    for(auto &e: _entries) {
        sum += e->size();
    }
    return sum;
}

Type Directory::type() {
    return Type::kDirectory;
}

std::string Directory::name() {
    return _name;
}

void Directory::add(std::unique_ptr<Entry>entry) {
    _index[entry->name()] = _entries.size();
    _entries.emplace_back(std::move(entry));
}

Entry* Directory::entry(std::string &name) {
    if(auto i = _index.find(name); i != _index.end()) {
        return _entries[i->second].get();
    }
    return nullptr;
}

std::vector<Entry*> Directory::entries() {
    std::vector<Entry*> es;
    for(auto &e: _entries) {
        es.emplace_back(e.get());
    }
    return es;
}

void ls(Directory *dir, std::istream &input) {
    // loop until the next char is $ and add each entry to dir
    while(input.peek() != '$' && input.peek() != EOF) {
        std::string line;
        std::getline(input, line);
        std::istringstream iss(line);
        if (line[0] >= '0' && line[0] <= '9') {
            // this is a file
            unsigned long size;
            std::string name;
            iss >> size >> name;
            std::unique_ptr file = std::make_unique<File>(std::move(name), size);
            dir->add(std::move(file));
        } else {
            std::string ignore;
            std::string name;
            iss >> ignore >> name;
            std::unique_ptr directory = std::make_unique<Directory>(std::move(name));
            dir->add(std::move(directory));
        }
    }
}

void process(Directory *root, std::istream &input) {
    std::stack<Directory*> path;
    path.push(root);
    std::string line;
    while(std::getline(input, line)) {
        std::string ignore;
        std::string command;
        std::istringstream iss(line);
        iss >> ignore >> command;
        if(command == "cd") {
            std::string name;
            iss>> name;
            if (name == "..") {
                path.pop();
            } else {
                Entry *entry = path.top()->entry(name);
                if (entry == nullptr) {
                    throw std::runtime_error("bad dir");
                }
                if (entry->type() != Type::kDirectory) {
                    throw std::runtime_error("not dir");
                }
                auto *target = dynamic_cast<Directory*>(entry);
                path.push(target);
            }
        } else {
            // ls
            ls(path.top(), input);
        }
    }
}

unsigned long sum(Directory *root) {
    std::stack<Directory *> path;
    unsigned long total = 0;
    path.push(root);
    while(!path.empty()) {
        Directory *cwd = path.top();
        if (cwd->size() <= 100000) {
            total += cwd->size();
        }
        std::vector<Entry*> entries = cwd->entries();
        path.pop();
        for(auto e: entries) {
            if (e->type() == Type::kDirectory) {
                auto dir = dynamic_cast<Directory*>(e);
                path.push(dir);
            }
        }
    }

    return total;
}

unsigned long smallest(Directory *root, unsigned long min) {
    unsigned long best = ULLONG_MAX;
    std::stack<Directory *> path;
    path.push(root);
    while(!path.empty()) {
        Directory *cwd = path.top();
        unsigned long size = cwd->size();
        if (size > min && size < best) {
            best = size;
        }
        std::vector<Entry*> entries = cwd->entries();
        path.pop();
        for(auto e: entries) {
            if (e->type() == Type::kDirectory) {
                auto dir = dynamic_cast<Directory*>(e);
                path.push(dir);
            }
        }
    }
    return best;
}


std::string day07(std::string &filename) {
    unsigned long total = 70000000;
    unsigned long required = 30000000;
    std::ifstream infile(filename);
    std::string line;
    Directory root("/");
    Directory *cwd = &root;

    //consume the cd /
    std::getline(infile, line);
    process(cwd, infile);
    unsigned long empty = total - cwd->size();
    unsigned long min = required - empty;

    std::ostringstream oss;
    oss << "part1: " << sum(cwd) << " part2: " << smallest(cwd, min);
    return oss.str();
}
