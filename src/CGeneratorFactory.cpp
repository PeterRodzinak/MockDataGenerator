//
// Created by Peperodz on 6. 10. 2023.
//

#include "CGeneratorFactory.h"
#include "generators/CBoolGenerator.h"
#include "generators/CConstantGenerator.h"
#include "generators/CIncrementGenerator.h"
#include "generators/CIntGenerator.h"
#include "generators/CStringGenerator.h"
#include "generators/CAnyOfGenerator.h"

#include <memory>
#include <stdexcept>

CGeneratorFactory::CGeneratorFactory() {
    createMap["boolean"] = CGeneratorFactory::createBoolGenerator;
    createMap["bool"] = CGeneratorFactory::createBoolGenerator;

    createMap["constant"] = CGeneratorFactory::createConstantGenerator;
    createMap["c"] = CGeneratorFactory::createConstantGenerator;

    createMap["increment"] = CGeneratorFactory::createIncrementGenerator;
    createMap["inc"] = CGeneratorFactory::createIncrementGenerator;

    createMap["integer"] = CGeneratorFactory::createIntGenerator;
    createMap["int"] = CGeneratorFactory::createIntGenerator;

    createMap["string"] = CGeneratorFactory::createStringGenerator;
    createMap["str"] = CGeneratorFactory::createStringGenerator;
    createMap["s"] = CGeneratorFactory::createStringGenerator;

    createMap["AnyOf"] = CGeneratorFactory::createAnyOfGenerator;
    createMap["anyof"] = CGeneratorFactory::createAnyOfGenerator;
    createMap["ao"] = CGeneratorFactory::createAnyOfGenerator;
}

std::pair<std::string, std::string> CGeneratorFactory::splitGeneratorPrompt(const std::string &generatorPrompt) const {
    std::size_t index = 0;
    std::size_t argsEnd;

    while (index < generatorPrompt.length() && generatorPrompt[index] != '(') {
        index++;
    }
    if (generatorPrompt[index] == '(') {
        std::size_t parenthesisCounter = 1;
        argsEnd = index + 1;
        while (argsEnd < generatorPrompt.length() && parenthesisCounter != 0) {
            if (generatorPrompt[argsEnd] == '(')
                parenthesisCounter++;
            if (generatorPrompt[argsEnd] == ')')
                parenthesisCounter--;
            argsEnd++;
        }

        if (argsEnd >= generatorPrompt.length() && parenthesisCounter > 0) {
            throw std::runtime_error("GeneratorCreate: Wrong ending of argument field");
        }
    }
    return {generatorPrompt.substr(0, index),
            index >= generatorPrompt.length() ? "" : generatorPrompt.substr(index + 1, argsEnd - index - 2)};
}

std::unique_ptr<CGenerator> CGeneratorFactory::createGenerator(const std::string &generatorPrompt) const {
    std::unique_ptr<CGenerator> resultGenerator;
    auto generatorResultPair = splitGeneratorPrompt(generatorPrompt);
    if (!createMap.count(generatorResultPair.first)) {
        throw std::runtime_error("An invalid generator has been prompted");
    }
    std::function<std::unique_ptr<CGenerator>(const std::string &)> generatorCreator;
    generatorCreator = createMap.at(generatorResultPair.first); // gives function to create a generator
    resultGenerator = generatorCreator(generatorResultPair.second); // actually generates the creator
    return resultGenerator;
}

std::unique_ptr<CGenerator> CGeneratorFactory::createBoolGenerator(const std::string &spec) {
    return std::make_unique<CBoolGenerator>(spec);
}

std::unique_ptr<CGenerator> CGeneratorFactory::createConstantGenerator(const std::string &spec) {
    return std::make_unique<CConstantGenerator>(spec);
}

std::unique_ptr<CGenerator> CGeneratorFactory::createIncrementGenerator(const std::string &spec) {
    return std::make_unique<CIncrementGenerator>(spec);
}

std::unique_ptr<CGenerator> CGeneratorFactory::createIntGenerator(const std::string &spec) {
    return std::make_unique<CIntGenerator>(spec);
}

std::unique_ptr<CGenerator> CGeneratorFactory::createStringGenerator(const std::string &spec) {
    return std::make_unique<CStringGenerator>(spec);
}

std::unique_ptr<CGenerator> CGeneratorFactory::createAnyOfGenerator(const std::string &spec) {
    return std::make_unique<CAnyOfGenerator>(spec);
}
