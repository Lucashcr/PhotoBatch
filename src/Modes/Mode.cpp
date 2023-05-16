#include "Mode.h"

#include <algorithm>
#include <chrono>

Mode::Mode(const std::string &filter, const std::string &folder)
    : m_Filter{filter}, m_Folder{folder}
{
}

const std::string &Mode::GetFilter() const
{
    return m_Filter;
}

const std::string &Mode::GetFolder() const
{
    return m_Folder;
}

std::vector<std::filesystem::path> Mode::GetFiles(const std::filesystem::path &extension) const
{
    std::vector<std::filesystem::path> files;
    int numSkippedFiles = 0;

    for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(GetFolder()))
    {
        const bool bIsFile = std::filesystem::is_regular_file(entry.path());
        const bool bMatchFilter = GetFilter().empty() || (Utils::Funcs::ToLower(entry.path().string()).find(GetFilter()) != std::string::npos);
        const bool bMatchExtension = extension.empty() || (Utils::Funcs::ToLower(entry.path().extension()) == extension);

        if (bIsFile && bMatchFilter && bMatchExtension)
            files.push_back(entry.path());
        else
            numSkippedFiles++;
    }

    std::cout << GetModeName() << "Número de arquivos encontrados: " << files.size() << std::endl;
    std::cout << GetModeName() << "Número de arquivos ignorados: " << numSkippedFiles << std::endl;

    return files;
}

void Mode::Run()
{
    auto start = std::chrono::system_clock::now();
    RunImpl();
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << GetModeName() << "Tempo gasto: " << elapsed.count() << "ms" << std::endl;
}
