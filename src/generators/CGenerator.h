#pragma once

#include <string>
#include <random>
#include <vector>

class CGenerator {
protected:
    bool repeat;
public:
    virtual ~CGenerator() = default;
    static std::vector<std::string> parseArgs(const std::string & args);
    virtual std::string generate() = 0;
};