#pragma once

// Librerias STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <map>
#include <unordered_map>

// Third Parties
#include <SFML/Graphics.hpp>
#include "Memory/TSharedPointer.h"
#include "Memory/TStaticPtr.h"
//#include "TUniquePtr.h"
#include "Memory/TWeakPointer.h"

// Librería Matemática
#include "Vectores\Vector2.h"
#include "Vectores\MathUtility.h"
#include "Vectores\Quaternion.h"
// Imgui
#include <imgui.h>
#include <imgui-SFML.h>

//Enums
enum ShapeType {
    EMPTY = 0,
    CIRCLE = 1,
    RECTANGLE = 2,
    TRIANGLE = 3,
    GENERIC = 4
};
enum ConsoleTypeError {
    NORMAL = 0,
    WARNING = 1,
    ERROR = 2,
    INFO = 3
};

// MACRO for safe release of resources
#define SAFE_PTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

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