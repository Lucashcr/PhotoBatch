#pragma once

#include "ArgumentParser.h"

namespace Utils
{
    namespace Args
    {
        namespace Flags
        {
            static constexpr const char *Convert = "convert";
            static constexpr const char *Help = "help";
            static constexpr const char *Rename = "rename";
            static constexpr const char *Resize = "resize";
            static constexpr const char *Scale = "scale";
        }
        namespace Options
        {
            static constexpr const char *Amount = "amount";
            static constexpr const char *Filter = "filter";
            static constexpr const char *Folder = "folder";
            static constexpr const char *From = "from";
            static constexpr const char *Preffix = "preffix";
            static constexpr const char *StartNumber = "startnumber";
            static constexpr const char *To = "to";
            static constexpr const char *Width = "width";
            static constexpr const char *Height = "height";
        }
    }

    namespace Funcs
    {
        std::string ToLower(std::string str);
        const std::string &GetInvalidChars();
        bool HasInvalidChars(const std::string &str);
        bool HasWhiteSpaces(const std::string &flag);
    }
}
