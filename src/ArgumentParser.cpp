#include "ArgumentParser.h"
#include "utils.h"


void ArgumentParser::RegisterFlag(const std::string& flag)
{
    if (!flag.empty() && !Utils::Funcs::HasWhiteSpaces(flag))
    {
        m_Flags[flag] = false;
    }
}

bool ArgumentParser::IsFlagRegistered(const std::string& flag) const
{
    if (!flag.empty())
    {
        return m_Flags.count(flag) == 1;
    }
    else
    {
        return false;
    }
}

bool ArgumentParser::GetFlag(const std::string& flag) const
{
    if (!flag.empty())
    {
        auto flagIterator = m_Flags.find(flag);
        if (flagIterator != end(m_Flags))
        {
            return flagIterator->second;
        }
    }
    
    return false;
}

void ArgumentParser::RegisterOption(const std::string& option)
{
    if (!option.empty() && !Utils::Funcs::HasWhiteSpaces(option))
    {
        m_Options[option] = "";
    }   
}

bool ArgumentParser::IsOptionRegistered(const std::string& option) const
{
    if (!option.empty())
    {
        return m_Options.count(option) == 1;
    }
    else
    {
        return false;
    }
}

const std::string& ArgumentParser::GetOption(const std::string& option) const
{
    if (!option.empty())
    {
        auto optionIterator = m_Options.find(option);
        if (optionIterator != end(m_Options))
        {
            return optionIterator->second;
        }
    }
    static std::string EmptyOption = "";
    return EmptyOption;
}

float ArgumentParser::GetOptionAsFloat(const std::string& option) const
{
    const std::string& optionValue = GetOption(option);
    if (!optionValue.empty())
    {
        return stof(optionValue);
    }
    return -1;
}

int ArgumentParser::GetOptionAsInt(const std::string& option) const
{
    const std::string& optionValue = GetOption(option);
    if (!optionValue.empty())
    {
        return stoi(optionValue);
    }
    return -1;
}

template<>
float ArgumentParser::GetOptionAs(const std::string& option) const { return GetOptionAsFloat(option); }

template<>
int ArgumentParser::GetOptionAs(const std::string& option) const { return GetOptionAsInt(option); }

template<>
std::string ArgumentParser::GetOptionAs(const std::string& option) const { return GetOption(option); }

void ArgumentParser::SetHelpMessage(const std::string& helpMessage)
{
    m_helpMessage = helpMessage;
}

const std::string& ArgumentParser::GetHelpMessage() const
{
    return ArgumentParser::m_helpMessage;
}

void ArgumentParser::Parse(int argc, char* argv[]) 
{
    if (argc > 1 && argv != nullptr)
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = Utils::Funcs::ToLower(argv[i]);

            if (arg.length() >= 3)
            {
                if (arg[0] == '-' && arg[1] == '-')
                {
                    arg = arg.substr(2);

                    if (arg.find_first_of('=') != std::string::npos)
                    {
                        // OPÇÃO
                        const size_t equalSingPos = arg.find('=');
                        if (equalSingPos != std::string::npos)
                        {
                            std::string optionName = arg.substr(0, equalSingPos);
                            std::string optionValue = arg.substr(equalSingPos + 1);

                            auto optionIterator = m_Options.find(optionName);
                            if (optionIterator != end(m_Options))
                            {
                                optionIterator->second = optionValue;
                            }
                        }
                    }
                    else
                    {
                        // FLAG
                        auto flagIterator = m_Flags.find(arg);
                        if (flagIterator != end(m_Flags))
                        {
                            flagIterator->second = true;
                        }
                    }
                }
            }
        }
    }
}