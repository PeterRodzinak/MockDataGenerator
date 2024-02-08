#pragma once

#include "CGenerator.h"

class CAnyOfGenerator : public CGenerator {
    std::vector<std::string> argList;
public:
    explicit CAnyOfGenerator(const std::string & args);
    std::string generate() override;
};