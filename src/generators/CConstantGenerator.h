#pragma once

#include "CGenerator.h"

class CConstantGenerator : public CGenerator{
    const std::string generatedConstant;
private:
    explicit CConstantGenerator(std::string & c) : CGenerator(false), generatedConstant(std::move(c)) {}
    std::string generate() const override;
};