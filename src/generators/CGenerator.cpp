//
// Created by Peperodz on 5. 10. 2023.
//

#include "CGenerator.h"

std::vector<std::string> CGenerator::parseArgs(const std::string &args) {
    std::vector<std::string> result;
    std::string arg;
    for (const char & c : args) {
        if (c == ' ' && !arg.empty()) {
            result.emplace_back(std::move(arg));
            arg = "";
        } else {
            arg.append(std::string(1, c));
        }
    }
    if (!arg.empty())
        result.emplace_back(std::move(arg));
    return result;
}
