//
// Created by ANDREW SMITH on 07/12/2022.
//

#ifndef AOC22_DAY07_H
#define AOC22_DAY07_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <climits>

enum Type {
    kFile,
    kDirectory
};

class Entry {
public:
    virtual unsigned long size() = 0;
    virtual Type type() = 0;
    virtual std::string name() = 0;

    virtual ~Entry() = default;
    Entry() = default;
    Entry(const Entry&) = default;
    Entry &operator=(const Entry&) = default;
    Entry(Entry &&) = default;
    Entry& operator=(Entry&&) = default;

};

class File: virtual public Entry {
public:
    File(std::string name, long size);

    unsigned long size() override;
    Type type() override;
    std::string name() override;

    ~File() override = default;
    File(const File &) = delete;
    File &operator=(const File &) = delete;
    File(File &&) = default;
    File &operator=(File &&) = default;

private:
    std::string _name;
    long _size;
};

class Directory: virtual public Entry {
public:
    explicit Directory(std::string name);

    unsigned long size() override;
    Type type() override;
    std::string name() override;
    void add(std::unique_ptr<Entry>entry);
    Entry* entry(std::string &name);
    std::vector<Entry *> entries();

    ~Directory() override = default;
    Directory(const File &) = delete;
    Directory &operator=(const Directory &) = delete;
    Directory(Directory &&) = default;
    Directory &operator=(Directory &&) = default;
private:
    std::vector<std::unique_ptr<Entry>> _entries;
    std::map<std::string, unsigned long> _index;
    std::string _name;

};

std::string day07(std::string &filename);

#endif //AOC22_DAY07_H
