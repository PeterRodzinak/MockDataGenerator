#pragma once

#include "CGenerator.h"

class CIncrementGenerator : public CGenerator{
private:
    int current;
    int increment;
public:
    CIncrementGenerator(const std::string & args);
    std::string generate() override;
};