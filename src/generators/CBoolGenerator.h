#pragma once

#include "CGenerator.h"

class CBoolGenerator : public CGenerator{
public:
    CBoolGenerator() : CGenerator(false) {}
    std::string generate() const override;
};