#include "CMockApp.h"
#include "formats/CCustomLine.h"
#include <stdexcept>
#include <iostream>

void CMockApp::run(int argc, char **argv) {
    if (argc == 1) {
        run();
        return;
    }
}

void CMockApp::run() {
    bool formatPassed = false;
    while (!formatPassed) {
        try {
            std::cout << "Select Format:";
            std::string input;
            std::cin >> std::skipws >> input;
            setFormat(input);
            formatPassed = true;
        } catch (std::exception & e) {
            std::cout << "Choice error: " << e.what() << std::endl;
        }
    }

    generatorFormat->promptGeneratorInput();

    std::size_t iterationNumber;
    bool iteratorPassed = false;
    while (!iteratorPassed) {
        try {
            std::cout << "Select number of iterations:";
            std::cin >> std::skipws >> iterationNumber;
            iteratorPassed = true;
        } catch (...) {
            std::cout << "Invalid number" << std::endl;
        }
    }

    for (size_t i = 0; i < iterationNumber; i++) {
        std::cout << generatorFormat->generateUnit() << std::endl;
    }
}

void CMockApp::setFormat(const std::string &formatName) {
    if (formatName == "Custom_Line" || formatName == "CL") {
        generatorFormat = std::make_unique<CCustomLine>();
    } else {
        throw std::logic_error("Invalid format name");
    }
}
