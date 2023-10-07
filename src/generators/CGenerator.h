#pragma once

#include <string>
#include <random>
#include <vector>

class CGenerator {
protected:
    bool repeat;
public:
    static std::vector<std::string> parseArgs(const std::string & args);
    virtual std::string generate() = 0;
};