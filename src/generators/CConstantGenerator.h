#pragma once

#include "CGenerator.h"

class CConstantGenerator : public CGenerator{
    const std::string generatedConstant;
private:
    explicit CConstantGenerator(std::string & c) : generatedConstant(std::move(c)) {repeat = false;}
    std::string generate() override;
};