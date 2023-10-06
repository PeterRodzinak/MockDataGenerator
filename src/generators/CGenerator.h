#pragma once

#include <string>
#include <random>

class CGenerator {
protected:
    bool repeat;
public:
    explicit CGenerator(bool r) : repeat(r){};
    virtual std::string generate() const = 0;
};