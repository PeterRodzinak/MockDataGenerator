//
// Created by Peperodz on 6. 10. 2023.
//

#include "CIncrementGenerator.h"

#include <stdexcept>

CIncrementGenerator::CIncrementGenerator(std::string &args) {
    current = 0;
    increment = 1;
    std::vector<std::string> argVec = parseArgs(args);
    for (auto & arg : argVec) {
        if (arg.find("cur=") != std::string::npos) {
            std::size_t begin = arg.find("cur=");
            std::size_t len = arg.size() - begin - 4;
            if (len == 0)
                throw std::runtime_error("Increment generator: wrong current argument");
            std::string sub = arg.substr(begin, len);
            current = stoi(sub);
        } else if (arg.find("inc=") != std::string::npos) {
            std::size_t begin = arg.find("inc=");
            std::size_t len = arg.size() - begin - 4;
            if (len == 0)
                throw std::runtime_error("Increment generator: wrong increment argument");
            std::string sub = arg.substr(begin, len);
            current = stoi(sub);
        } else {
            throw std::runtime_error("Increment generator: wrong argument");
        }
    }
}

std::string CIncrementGenerator::generate() {
    int printedNumber = current;
    current += increment;
    return std::to_string(printedNumber);
}
