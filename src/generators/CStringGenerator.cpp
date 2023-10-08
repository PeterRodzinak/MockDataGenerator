//
// Created by Peperodz on 6. 10. 2023.
//

#include "CStringGenerator.h"

#include <stdexcept>

CStringGenerator::CStringGenerator(std::string &args) {
    setTable["alpha"] = "abcdefghijklmnopqrstuvwxyz";
    setTable["num"] = "0123456789";
    setTable["alphanum"] = "0123456789abcdefghijklmnopqrstuvwxyz";
    setTable["fullInt"] = "0123456789abcdefghijklmnopqrstuvwxyz+-*/\\?!@#$%^&*(),.:;|";
    std::vector<std::string> argVec = parseArgs(args);
    length = 10;
    usedSet = &(setTable["alpha"]);
    repeat = true;
    for (auto & arg : argVec) {
        if (setTable.count(arg)) {
            usedSet = &(setTable[arg]);
        } else if (arg.find("l=") == 0) {
            std::size_t lenCharSize = arg.size() - 2;
            if (lenCharSize == 0)
                throw std::runtime_error("StringGenerator: Invalid length");
            length = std::stoi(arg.substr(2, lenCharSize));
            if (length == 0)
                throw std::runtime_error("StringGenerator: Invalid length");
        } else if (arg.find("-r") == 0 && arg.length() == 2) {
            repeat = false;
        } else {
            throw std::runtime_error("StringGenerator: Wrong argument");
        }
    }
}

std::string CStringGenerator::generate() {
    std::string generatedWord;
    generatedWord = std::string(length, ' ');
    do {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<std::size_t> distribution(0, usedSet->length());
        for (auto & c : generatedWord) {
            c = (*usedSet)[distribution(gen)];
        }
    } while (!repeat && !usedStrings.count(generatedWord));
    return generatedWord;
}
