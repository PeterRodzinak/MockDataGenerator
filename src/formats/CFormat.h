#pragma once

#include "../generators/CGenerator.h"
#include "../CGeneratorFactory.h"
#include <string>
#include <memory>

class CFormat {
protected:
    CGeneratorFactory generatorFactory;
public:
    virtual ~CFormat() = default;
    virtual void promptGeneratorInput() = 0;
    virtual void getGeneratorInput(const std::string & formatPrompt) = 0;
    virtual std::string generateUnit() = 0;
};
