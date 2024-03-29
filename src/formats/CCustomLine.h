#pragma once

#include "CFormat.h"

class CCustomLine : public CFormat {
private:
    std::vector<std::unique_ptr<CGenerator>> generationPattern;
    std::size_t generationCount;

public:
    explicit CCustomLine() = default;

    void promptGeneratorInput() override;
    void getGeneratorInput(const std::string & formatPrompt) override;
    std::vector<std::string> generateOutput() override;
};