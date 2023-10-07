#pragma once

#include "CGenerator.h"
#include <unordered_set>

class CStringGenerator : public CGenerator{
private:
    std::unordered_set<std::string> usedStrings;
    std::size_t length;
    int writingState;
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::string alphaNum = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::string fullInterpunction = "0123456789abcdefghijklmnopqrstuvwxyz+-*/\\?!@#$%^&*(),.:;|";
public:
    CStringGenerator(std::string & args);
    std::string generate() override;
};