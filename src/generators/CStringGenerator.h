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
    explicit CStringGenerator(std::size_t l) : CGenerator(false), length(l), writingState(0) {}
    CStringGenerator(bool r, std::size_t l, int state) : CGenerator(r), length(l), writingState(state) {};
    std::string generate() const override;
};