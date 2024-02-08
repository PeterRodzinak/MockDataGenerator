#include "CCustomLine.h"
#include <iostream>

std::vector<std::string> CCustomLine::generateOutput() {
    std::vector<std::string> generatedOutput;

    for (auto i = 0; i < generationCount; i++) {
        generatedOutput.emplace_back();
        for (auto & generator : generationPattern) {
            generatedOutput[i].append(generator->generate());
        }
    }

    return generatedOutput;
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
        std::cout << "Prompt generators:";
        std::string input;
        std::getline(std::cin, input);
        try {
            getGeneratorInput(input);
        } catch (std::exception & e) {
            std::cout << "Prompt error: " << e.what() << std::endl;
        }
        if (generationPattern.empty()) {
            std::cout << "Prompt at least one generator" << std::endl;
            continue;
        }
        passed = true;
    }

    passed = false;
    while (!passed) {
        std::cout << "Prompt number of generations:";
        try {
            std::cin >> generationCount;
        } catch (...) {
            std::cout << "Prompt a correct number please" << std::endl;
        }
        passed = true;
    }
}
