#pragma once

#include "CGenerator.h"

class CIncrementGenerator : public CGenerator{
private:
    int current;
public:
    std::string generate() const override;
};