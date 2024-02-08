#pragma once

#include "../generators/CGenerator.h"
#include "../CGeneratorFactory.h"
#include <string>
#include <memory>
#include <vector>

class CFormat {
protected:
    CGeneratorFactory generatorFactory;

    std::vector<std::string> splitGeneratorLine(const std::string & generatorLine) const;
public:
    virtual ~CFormat() = default;
    virtual void promptGeneratorInput() = 0;
    virtual void getGeneratorInput(const std::string & formatPrompt) = 0;
    virtual std::vector<std::string> generateOutput() = 0;
};
