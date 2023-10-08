#pragma once

#include "CFormat.h"

class CCustomLine : public CFormat {
private:
    std::vector<std::unique_ptr<CGenerator>> generationPattern;

    std::vector<std::string> splitGeneratorLine(const std::string & generatorLine) const;
public:
    CCustomLine(const std::string & generatorLine);
    std::string generateUnit() override;
};