#pragma once

#include "CGenerator.h"
#include <unordered_set>
#include <climits>

class CIntGenerator : public CGenerator{
private:
    std::unordered_set<int> usedNumbers;
    long long int minimalInt;
    long long int maximumInt;
public:
    CIntGenerator() : CGenerator(false), minimalInt(LLONG_MIN), maximumInt(LLONG_MAX) {};
    CIntGenerator(bool r, long long int min, long long int max)
    : CGenerator(r), minimalInt(min), maximumInt(max) {};

    std::string generate() const override;
};