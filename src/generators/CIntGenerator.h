#pragma once

#include "CGenerator.h"
#include <unordered_set>
#include <climits>

class CIntGenerator : public CGenerator{
private:
    std::unordered_set<long long int> usedNumbers;
    long long int minimalInt;
    long long int maximumInt;
public:
    explicit CIntGenerator(const std::string & args);
    std::string generate() override;
};