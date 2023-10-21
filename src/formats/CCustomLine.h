#pragma once

#include "CFormat.h"

class CCustomLine : public CFormat {
private:
    std::vector<std::unique_ptr<CGenerator>> generationPattern;

    std::vector<std::string> splitGeneratorLine(const std::string & generatorLine) const;
public:
    explicit CCustomLine() = default;

    void promptGeneratorInput() override;
    void getGeneratorInput(const std::string & formatPrompt) override;
    std::string generateUnit() override;
};