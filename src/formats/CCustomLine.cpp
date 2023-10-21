#include "CCustomLine.h"
#include <iostream>

std::vector<std::string> CCustomLine::splitGeneratorLine(const std::string &generatorLine) const {
    std::vector<std::string> resultGeneratorPrompts;
    std::string generatorPrompt;
    for (char i : generatorLine) {
        if (i == ',') {
            resultGeneratorPrompts.emplace_back(std::move(generatorPrompt));
            generatorPrompt.clear();
        } else {
            generatorPrompt.append(std::string(1, i));
        }
    }
    if (!generatorPrompt.empty())
        resultGeneratorPrompts.emplace_back(std::move(generatorPrompt));
    return resultGeneratorPrompts;
}

std::string CCustomLine::generateUnit() {
    std::string generatedLine;
    for (auto & generator : generationPattern) {
        generatedLine.append(generator->generate());
    }
    return generatedLine;
}

void CCustomLine::getGeneratorInput(const std::string &formatPrompt) {
    std::vector<std::string> generatorPrompts = splitGeneratorLine(formatPrompt);
    try {
        for (auto & prompt : generatorPrompts)
            generationPattern.emplace_back(std::move(generatorFactory.createGenerator(prompt)));
    } catch (std::exception & e) {
        generationPattern.clear();
        throw e;
    }
}

void CCustomLine::promptGeneratorInput() {
    bool passed = false;
    while (!passed) {
        try {
            std::cout << "Prompt generators:";
            std::string input;
            std::cin.ignore();
            std::getline(std::cin, input);
            getGeneratorInput(input);
            passed = true;
        } catch (std::exception & e) {
            std::cout << "Custom Line error: " << e.what() << std::endl;
        }
    }
}
