#pragma once

#include <iostream>
#include <map>


/**
 * Classe para "parsear" os argumentos passados pela linha de comando...
 * 
 * Exemplo de utilização:
 *     ArgumentParser argParser;
 *     argParse.RegisterFlag("<flagname>");
 *     argParse.Parse(argc, argv);
 *     argParse.GetFlag("<flagname>");
*/
class ArgumentParser {

public:
    // Registra uma flag
    void RegisterFlag(const std::string& flag);
    
    // Recupera uma flag
    bool GetFlag(const std::string& flag) const;

    // Verifica se a flag está registrada
    bool IsFlagRegistered(const std::string& flag) const;

    // Registra uma opção
    void RegisterOption(const std::string& option);

    // Verifica se a opção está registrada
    bool IsOptionRegistered(const std::string& option) const;

    // Recuperar uma opção convertida para o tipo informado
    template<typename T>
    T GetOptionAs(const std::string& option) const;

    // Realizar o parse dos argumentos passados
    void Parse(int argc, char* argv[]);

    // Define a mensagem de ajuda
    void SetHelpMessage(const std::string& helpMessage);
    
    // Recupera a mensagem de ajuda
    const std::string& GetHelpMessage() const;

private:
    // Mapa de flags
    std::map<std::string, bool> m_Flags;
    
    // Mapa de opções
    std::map<std::string, std::string> m_Options;

    // Mensagem de ajuda
    std::string m_helpMessage;
    
    // Recupera uma opção como std::string
    const std::string& GetOption(const std::string& option) const;
    
    // Recupera uma opção convertida para float
    float GetOptionAsFloat(const std::string& option) const;
    
    // Recupera uma opção convertida para int
    int GetOptionAsInt(const std::string& option) const;
};
