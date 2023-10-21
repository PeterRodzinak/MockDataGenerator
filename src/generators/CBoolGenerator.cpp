//
// Created by Peperodz on 6. 10. 2023.
//

#include "CBoolGenerator.h"

#include <stdexcept>

CBoolGenerator::CBoolGenerator(const std::string &args) {
    if (!args.empty())
        throw std::runtime_error("BoolGen: too many args");
    repeat = false;
}

std::string CBoolGenerator::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(gen) ? "true" : "false";
}
