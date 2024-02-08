#pragma once

#include "generators/CGenerator.h"
#include <memory>
#include <unordered_map>
#include <functional>

class CGeneratorFactory {
private:
    std::unordered_map<std::string, std::function<std::unique_ptr<CGenerator>(const std::string &)>> createMap;

    std::pair<std::string, std::string> splitGeneratorPrompt(const std::string & generatorPrompt) const;

    static std::unique_ptr<CGenerator> createBoolGenerator(const std::string & spec);
    static std::unique_ptr<CGenerator> createConstantGenerator(const std::string & spec);
    static std::unique_ptr<CGenerator> createIncrementGenerator(const std::string & spec);
    static std::unique_ptr<CGenerator> createIntGenerator(const std::string & spec);
    static std::unique_ptr<CGenerator> createStringGenerator(const std::string & spec);
    static std::unique_ptr<CGenerator> createAnyOfGenerator(const std::string & spec);
public:
    CGeneratorFactory();
    std::unique_ptr<CGenerator> createGenerator(const std::string & generatorPrompt) const;
};
