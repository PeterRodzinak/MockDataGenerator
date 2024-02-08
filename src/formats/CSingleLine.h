#pragma once

#include "CFormat.h"

class CSingleLine : public CFormat{
    std::unique_ptr<CGenerator> generator;
    std::string separator;
    std::size_t generationCount;
public:
    void promptGeneratorInput() override;
    void getGeneratorInput(const std::string & formatPrompt) override;
    std::vector<std::string> generateOutput() override;
};