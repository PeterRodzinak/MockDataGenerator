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
    CIntGenerator(std::string & args);
    std::string generate() override;
};