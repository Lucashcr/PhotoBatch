#include "Mode.h"

#include <algorithm>
#include <chrono>

#include "ConvertMode.h"
#include "RenameMode.h"
#include "ResizeMode.h"
#include "ScaleMode.h"

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

std::unique_ptr<Mode> CreateMode(const ArgumentParser &argParser)
{
    const bool bConvertMode = argParser.GetFlag(Utils::Args::Flags::Convert);
    const bool bRenameMode = argParser.GetFlag(Utils::Args::Flags::Rename);
    const bool bResizeMode = argParser.GetFlag(Utils::Args::Flags::Resize);
    const bool bScaleMode = argParser.GetFlag(Utils::Args::Flags::Scale);

    const bool bHelp = argParser.GetFlag(Utils::Args::Flags::Help);

    /**
     *
     *  ^ -> OU EXCLUSIVO
     *
     *  Lógica
     *      1 ^ 1 == 0
     *      1 ^ 0 == 1
     *      0 ^ 1 == 1
     *      0 ^ 0 == 0
     *
     */

    if (!(bConvertMode ^ bRenameMode ^ bResizeMode ^ bScaleMode))
    {
        throw std::invalid_argument("Somente um modo pode estar ativo");
    }

    const std::string filter = argParser.GetOptionAs<std::string>(Utils::Args::Options::Filter);
    if (!filter.empty())
    {
        if (Utils::Funcs::HasInvalidChars(filter))
        {
            throw std::invalid_argument("O filter não pode conter os caracteres " + Utils::Funcs::GetInvalidChars());
        }
    }

    const std::string folder = argParser.GetOptionAs<std::string>(Utils::Args::Options::Folder);
    if (folder.empty())
    {
        throw std::invalid_argument("A pasta não pode estar em branco...");
    }

    if (!std::filesystem::exists(folder))
    {
        throw std::invalid_argument("A pasta informada não existe...");
    }

    if (bConvertMode)
    {
        const std::string from = argParser.GetOptionAs<std::string>(Utils::Args::Options::From);
        const std::string to = argParser.GetOptionAs<std::string>(Utils::Args::Options::To);

        const std::array<std::string, 2> convertOptions = {"jpg", "png"};

        const bool bIsFromValid = find(
            begin(convertOptions),
            end(convertOptions),
            from);

        const bool bIsToValid = find(
            begin(convertOptions),
            end(convertOptions),
            from);

        if (!bIsFromValid || !bIsToValid)
        {
            throw std::invalid_argument("As opções From e To precisam ser \".png\" ou \".jpg\"...");
        }
        if (from == to)
        {
            throw std::invalid_argument("As opções From e To precisam ser diferentes...");
        }

        const std::map<std::string, ConvertMode::Format> convertOptionsMap = {
            {"jpg", ConvertMode::Format::JPG},
            {"png", ConvertMode::Format::PNG}};

        return std::make_unique<ConvertMode>(
            filter,
            folder,
            convertOptionsMap.at(from),
            convertOptionsMap.at(to));
    }

    if (bRenameMode)
    {
        int startNumber = -1;

        try
        {
            startNumber = argParser.GetOptionAs<int>(Utils::Args::Options::StartNumber);
        }
        catch (const std::invalid_argument &)
        {
            throw std::invalid_argument("O valor informado para o StartNumber precisa ser um valor numérico...");
        }

        if (startNumber < 0)
        {
            throw std::invalid_argument("O valor informado para a opção StartNumber deve ser maior que 0...");
        }

        std::string preffix = argParser.GetOptionAs<std::string>(Utils::Args::Options::Preffix);
        if (Utils::Funcs::HasInvalidChars(preffix))
        {
            throw std::invalid_argument("A opção Preffix não pode conter os caracteres " + Utils::Funcs::GetInvalidChars());
        }

        return std::make_unique<RenameMode>(filter, folder, preffix, startNumber);
    }

    if (bResizeMode)
    {
        int width = 0, height = 0;

        try
        {
            height = argParser.GetOptionAs<int>(Utils::Args::Options::Height);
            width = argParser.GetOptionAs<int>(Utils::Args::Options::Width);
        }
        catch (const std::invalid_argument &)
        {
            throw std::invalid_argument("O valores informados para o Width e o Height precisam ser valores numéricos...");
        }

        if (width <= 0 || height <= 0)
        {
            throw std::invalid_argument("Os valores informados para o Width e Height devem ser maiores que 0...");
        }
        if (filter.empty())
        {
            throw std::invalid_argument("Filter não pode estar vazio no modo Resize...");
        }

        return std::make_unique<ResizeMode>(filter, folder, width, height);
    }

    if (bScaleMode)
    {
        float amount = 0;

        try
        {
            amount = argParser.GetOptionAs<float>(Utils::Args::Options::Amount);
        }
        catch (const std::invalid_argument &)
        {
            throw std::invalid_argument("O valor informado para o Amount precisa ser um valor numérico...");
        }

        if (amount <= 0.0f)
        {
            throw std::invalid_argument("O valor informado para o Amount precisa ser maior do que zero...");
        }
        if (filter.empty())
        {
            throw std::invalid_argument("Filter não pode estar vazio no modo Scale...");
        }

        return std::make_unique<ScaleMode>(filter, folder, amount);
    }

    return nullptr;
}