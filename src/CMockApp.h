#pragma once

#include "formats/CFormat.h"

class CMockApp {
private:
    std::unique_ptr<CFormat> generatorFormat;

    void setFormat(const std::string & formatName);
public:
    CMockApp() = default;
    void run(int argc, char ** argv);
    void run();
};