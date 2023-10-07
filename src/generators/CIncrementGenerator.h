#pragma once

#include "CGenerator.h"

class CIncrementGenerator : public CGenerator{
private:
    int current;
    int increment;
public:
    CIncrementGenerator(std::string & args);
    std::string generate() override;
};