#include "CMockApp.h"
#include "formats/CCustomLine.h"
#include "formats/CSingleLine.h"
#include <stdexcept>
#include <iostream>

void CMockApp::run(int argc, char **argv) {
    if (argc == 1) {
        run();
        return;
    }
}

void CMockApp::run() {
    generatorFormat = nullptr;
    while (generatorFormat == nullptr) {
        std::cout << "Select Format:";
        std::string input;
        std::cin >> std::skipws >> input;
        std::cin.ignore();
        setFormat(input);
        if (generatorFormat == nullptr)
        std::cout << "Invalid generator name" << std::endl;
    }

    generatorFormat->promptGeneratorInput();

    auto generatedOutput = std::move(generatorFormat->generateOutput());
    for (auto & unit : generatedOutput) {
        std::cout << unit << std::endl;
    }
}

void CMockApp::setFormat(const std::string &formatName) {
    if (formatName == "Custom_Line" || formatName == "CL") {
        generatorFormat = std::make_unique<CCustomLine>();
    } else if (formatName == "Single_Line" || formatName == "SL") {
        generatorFormat = std::make_unique<CSingleLine>();
    } else {
        generatorFormat = nullptr;
    }
}
