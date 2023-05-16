#include "PhotoBatch.h"

#include <iostream>

#include "ArgumentParser.h"
#include "Modes/Mode.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "pt_BR");
    setlocale(LC_NUMERIC, "en_US");

    ArgumentParser argParser;
    argParser.RegisterFlag(Utils::Args::Flags::Convert);
    argParser.RegisterFlag(Utils::Args::Flags::Help);
    argParser.RegisterFlag(Utils::Args::Flags::Rename);
    argParser.RegisterFlag(Utils::Args::Flags::Resize);
    argParser.RegisterFlag(Utils::Args::Flags::Scale);

    argParser.RegisterOption(Utils::Args::Options::Amount);
    argParser.RegisterOption(Utils::Args::Options::Filter);
    argParser.RegisterOption(Utils::Args::Options::Folder);
    argParser.RegisterOption(Utils::Args::Options::From);
    argParser.RegisterOption(Utils::Args::Options::Height);
    argParser.RegisterOption(Utils::Args::Options::Preffix);
    argParser.RegisterOption(Utils::Args::Options::StartNumber);
    argParser.RegisterOption(Utils::Args::Options::To);
    argParser.RegisterOption(Utils::Args::Options::Width);

    argParser.SetHelpMessage(helpmessage);

    argParser.Parse(argc, argv);

    if (argParser.GetFlag(Utils::Args::Flags::Help))
    {
        std::cout << argParser.GetHelpMessage() << std::endl;
    }
    else
    {
        try
        {
            if (std::unique_ptr<Mode> PhotoBatchMode = CreateMode(argParser))
            {
                PhotoBatchMode->Run();
            }
        }
        catch (const std::exception &exception)
        {
            std::cerr << exception.what() << std::endl;
            std::cerr << "Para mais informações, rode o PhotoBatch com a flag --help" << std::endl;
        }
    }

    return 0;
}