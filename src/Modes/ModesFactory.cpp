#include "ModesFactory.h"

#include "ConvertMode.h"
#include "RenameMode.h"
#include "ResizeMode.h"
#include "ScaleMode.h"

#include <algorithm>

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

        const std::map<std::string, ConvertMode::Format> convertOptionsMap = {
            {"jpg", ConvertMode::Format::JPG},
            {"png", ConvertMode::Format::PNG}};

        const bool bIsFromValid = convertOptionsMap.find(from) != end(convertOptionsMap);
        const bool bIsToValid = convertOptionsMap.find(to) != end(convertOptionsMap);

        if (!bIsFromValid || !bIsToValid)
        {
            throw std::invalid_argument("As opções From e To precisam ser \".png\" ou \".jpg\"...");
        }
        if (from == to)
        {
            throw std::invalid_argument("As opções From e To precisam ser diferentes...");
        }

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