#pragma once

// Librerias STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>

// Third Parties
#include <SFML/Graphics.hpp>
#include "Memory/TSharedPointer.h"
#include "Memory/TStaticPtr.h"
//#include "TUniquePtr.h"
#include "Memory/TWeakPointer.h"

//Enums
enum ShapeType {
    NONE = 0,
    CIRCLE = 1,
    RECTANGLE = 2,
    TRIANGLE = 3,
};

// MACRO for safe release of resources
#define SAFEPTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

#define MESSAGE(classObj, method, state)                      \
{                                                             \
    std::ostringstream os;                                   \
    os << classObj << "::" << method << " : "                \
        << "[CREATION OF RESOURCE" << ": " << state "] \n";\
    std::cerr << os.str();                                   \
}

#define ERROR(classObj, method, errorMSG, ptr)                         \
{                                                                 \
    std::ostringstream os;                                       \
    os << "ERROR : " << classObj << "::" << method << " : "      \
        << "  Error in data from params [" << errorMSG"] \n"; \
    std::cerr << os.str();                                       \
    exit(1);                                                      \
}