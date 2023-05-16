#include "RenameMode.h"

#include <filesystem>
#include <vector>

RenameMode::RenameMode(const std::string &filter, const std::string &folder, const std::string &preffix, int startNumber)
    : Mode{filter, folder}, m_Preffix{preffix}, m_StartNumber{startNumber}
{
}

const std::string &RenameMode::GetModeName() const
{
    static const std::string RenameModeName = "[Renomear]: ";
    return RenameModeName;
}

void RenameMode::RunImpl()
{
    std::cout << "-----------------PHOTOBATCH-----------------" << std::endl;
    std::cout << "Modo: Renomear" << std::endl;
    std::cout << "Pasta: " << GetFolder() << std::endl;
    std::cout << "Filtro: " << GetFilter() << std::endl;
    std::cout << "Prefixo: " << m_Preffix << std::endl;
    std::cout << "Número inicial: " << m_StartNumber << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    int currentNumber = m_StartNumber;
    for (std::filesystem::path &filepath : GetFiles())
    {
        const std::string newFileName = m_Preffix + std::to_string(currentNumber) + filepath.extension().string();

        try
        {
            std::filesystem::rename(filepath, filepath.parent_path() / newFileName);
            std::cout << GetModeName() << "Convertido com sucesso para " << filepath.parent_path() / newFileName << std::endl;
            currentNumber++;
        }
        catch (std::exception &exception)
        {
            std::cout << GetModeName() << "Erro ao renomear " << filepath.filename() << ":\n"
                      << exception.what() << std::endl;
        }
    }

    std::cout << GetModeName() << "Arquivos renomeados com sucesso!" << std::endl;
}