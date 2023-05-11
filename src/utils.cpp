#include <algorithm>
#include <iostream>
#include <filesystem>

#include "utils.h"
#include "ArgumentParser.h"
#include "Mode.h"

std::string Utils::Funcs::ToLower(std::string str)
{
    // for (char& c : str)
    // {
    //     c = std::tolower(c);
    // }
    
    std::transform(std::begin(str), std::end(str), std::begin(str),
                   [](unsigned char c){ return std::tolower(c); } );
    return str;
}

const std::string& Utils::Funcs::GetInvalidChars()
{
    static const std::string invalidCharacters = "\\/*?\"<>|$:";
    return invalidCharacters;
}

bool Utils::Funcs::HasInvalidChars(const std::string& str)
{
    const bool bHasInvalidChars = str.find_first_of(GetInvalidChars()) != std::string::npos;
    return bHasInvalidChars;
}

bool Utils::Funcs::HasWhiteSpaces(const std::string& str)
{
    return str.find(' ') != std::string::npos;
}