#pragma once

#include "CGenerator.h"

class CConstantGenerator : public CGenerator{
    const std::string generatedConstant;
public:
    explicit CConstantGenerator(const std::string & c) : generatedConstant(c) {repeat = false;}
    std::string generate() override;
};