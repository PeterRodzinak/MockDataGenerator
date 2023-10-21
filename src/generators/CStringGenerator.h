#pragma once

#include "CGenerator.h"
#include <unordered_set>
#include <unordered_map>

class CStringGenerator : public CGenerator{
private:
    std::unordered_set<std::string> usedStrings;
    std::size_t length;
    std::string * usedSet;
    std::unordered_map<std::string, std::string> setTable;
public:
    explicit CStringGenerator(const std::string & args);
    std::string generate() override;
};