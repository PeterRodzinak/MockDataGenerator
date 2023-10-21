#pragma once

#include "CGenerator.h"

class CBoolGenerator : public CGenerator{
public:
    CBoolGenerator(const std::string & args);
    std::string generate() override;
};