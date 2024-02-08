//
// Created by Peperodz on 5. 10. 2023.
//

#include "CGenerator.h"

std::vector<std::string> CGenerator::parseArgs(const std::string &args) {
    std::vector<std::string> result;
    std::string arg;
    bool readws = false;

    for (const char & c : args) {
        if (c == '"' && !readws)
            readws = true;
        if (c == '"' && readws)
            readws = false;
        if (c == ' ' && !readws && !arg.empty()) {
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
