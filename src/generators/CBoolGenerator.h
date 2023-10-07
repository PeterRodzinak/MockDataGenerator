#pragma once

#include "CGenerator.h"

class CBoolGenerator : public CGenerator{
public:
    CBoolGenerator(std::string & args);
    std::string generate() override;
};