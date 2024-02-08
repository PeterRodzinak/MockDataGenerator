//
// Created by Peperodz on 26. 10. 2023.
//

#include "CAnyOfGenerator.h"

CAnyOfGenerator::CAnyOfGenerator(const std::string &args) {
    argList = parseArgs(args);
}

std::string CAnyOfGenerator::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> distribution(0, argList.size() - 1);
    return argList.at(distribution(gen));
}
