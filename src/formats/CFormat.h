#pragma once

#include "../generators/CGenerator.h"
#include <string>
#include <memory>

class CFormat {
public:
    virtual std::string generateUnit() = 0;
};
