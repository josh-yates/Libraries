#ifndef VALIDINT_H
#define VALIDINT_H

//Validate an integer

#include <string>
#include <sstream>
#include <limits>

bool isInt(const std::string InputString, std::string& ErrMessage);

bool intInRange(const int InputInt, const int MinVal, const int MaxVal);

#endif