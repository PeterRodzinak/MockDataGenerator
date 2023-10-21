//
// Created by Peperodz on 6. 10. 2023.
//

#include "CIntGenerator.h"

#include <climits>
#include <stdexcept>

CIntGenerator::CIntGenerator(const std::string &args) {
    maximumInt = LLONG_MAX;
    minimalInt = LLONG_MIN;
    repeat = true;
    std::vector<std::string> argVec = parseArgs(args);
    for (auto & arg : argVec) {
        if (arg.find("max=")  == 0) {
            std::size_t numberCharSize = arg.size() - 4;
            if (numberCharSize == 0)
                throw std::runtime_error("StringGenerator: Invalid limit");
            maximumInt = std::stoi(arg.substr(4, numberCharSize));
        } else if (arg.find("min=") == 0) {
            std::size_t numberCharSize = arg.size() - 4;
            if (numberCharSize == 0)
                throw std::runtime_error("StringGenerator: Invalid limit");
            minimalInt = std::stoi(arg.substr(4, numberCharSize));
        } else if (arg.find("-r") == 0 && arg.length() == 2) {
            repeat = false;
        } else {
            throw std::runtime_error("StringGenerator: Invalid argument");
        }
    }
}

std::string CIntGenerator::generate() {
    long long int generatedNumber;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long int> distribution(minimalInt, maximumInt);
    do {
        generatedNumber = distribution(gen);
    } while (!repeat && !usedNumbers.count(generatedNumber));
    return std::to_string(generatedNumber);
}
