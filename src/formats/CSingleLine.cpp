//
// Created by Peperodz on 26. 10. 2023.
//

#include "CSingleLine.h"

#include <iostream>

void CSingleLine::promptGeneratorInput() {
    generator = nullptr;
    std::string input;
    while (generator == nullptr) {
        try {
            std::cout << "Prompt generators:";
            getline(std::cin, input);
            getGeneratorInput(input);
        } catch (std::exception & e) {
            generator = nullptr;
            std::cout << "Single Line error: " << e.what() << std::endl;
        }
    }

    bool passed = false;
    while (!passed) {
        try {
            std::cout << "Prompt separator:";
            getline(std::cin, input);
            separator = input;
            passed = true;
        } catch (std::exception & e) {
            std::cout << "Single Line error: " << e.what() << std::endl;
        }
    }

    passed = false;
    while (!passed) {
        try {
            std::cout << "Prompt generation count:";
            std::cin >> generationCount;
            std::cin.ignore();
            passed = true;
        } catch (std::exception & e) {
            std::cout << "Single Line error: " << e.what() << std::endl;
        }
    }
}

void CSingleLine::getGeneratorInput(const std::string &formatPrompt) {
    std::vector<std::string> genVec = splitGeneratorLine(formatPrompt);
    if (genVec.size() != 1)
        throw std::runtime_error("Incorrect amount of arguments - only one is used");
    try {
        generator = std::move(generatorFactory.createGenerator(formatPrompt));
    } catch (std::exception & e) {
        throw e;
    }
}

std::vector<std::string> CSingleLine::generateOutput() {
    std::string generatedLine;
    for (auto i = 0; i < generationCount; i++) {
        generatedLine.append(generator->generate());
        if (generationCount - i != 1) {
            generatedLine.append(separator);
        }
    }
    return {generatedLine};
}
