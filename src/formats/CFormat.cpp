//
// Created by Peperodz on 6. 10. 2023.
//

#include "CFormat.h"

std::vector<std::string> CFormat::splitGeneratorLine(const std::string &generatorLine) const {
    std::vector<std::string> resultGeneratorPrompts;
    std::string generatorPrompt;
    for (char i : generatorLine) {
        if (i == ',') {
            resultGeneratorPrompts.emplace_back(std::move(generatorPrompt));
            generatorPrompt.clear();
        } else {
            generatorPrompt.append(std::string(1, i));
        }
    }
    if (!generatorPrompt.empty())
        resultGeneratorPrompts.emplace_back(std::move(generatorPrompt));
    return resultGeneratorPrompts;
}