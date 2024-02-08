cmake_minimum_required(VERSION 3.22)
project(MockDataGenerator)

set(CMAKE_CXX_STANDARD 17)

add_executable(MockDataGenerator src/main.cpp
        src/CMockApp.cpp
        src/CMockApp.h
        src/generators/CGenerator.cpp
        src/generators/CGenerator.h
        src/generators/CIntGenerator.cpp
        src/generators/CIntGenerator.h
        src/generators/CStringGenerator.cpp
        src/generators/CStringGenerator.h
        src/generators/CBoolGenerator.cpp
        src/generators/CBoolGenerator.h
        src/CGeneratorFactory.cpp
        src/CGeneratorFactory.h
        src/generators/CIncrementGenerator.cpp
        src/generators/CIncrementGenerator.h
        src/generators/CConstantGenerator.cpp
        src/generators/CConstantGenerator.h
        src/formats/CCustomLine.cpp
        src/formats/CCustomLine.h
        src/formats/CFormat.cpp
        src/formats/CFormat.h
        src/formats/CCommaSeparatedValue.cpp
        src/formats/CCommaSeparatedValue.h
        src/formats/CJson.cpp
        src/formats/CJson.h
        src/formats/CSingleLine.cpp
        src/formats/CSingleLine.h
        src/generators/CAnyOfGenerator.cpp
        src/generators/CAnyOfGenerator.h
        src/generators/CFloatGenerator.cpp
        src/generators/CFloatGenerator.h
)
