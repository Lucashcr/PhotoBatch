#include "ConvertMode.h"

ConvertMode::ConvertMode(const std::string &filter, const std::string &folder, Image::Format fromFormat, Image::Format toFormat)
    : Mode{filter, folder}, m_FromFormat{fromFormat}, m_ToFormat{toFormat}
{
}

const std::string &ConvertMode::GetModeName() const
{
    static const std::string ConvertModeName{"[Converter]: "};
    return ConvertModeName;
}

void ConvertMode::RunImpl()
{
    std::cout << "-----------------PHOTOBATCH-----------------" << std::endl;
    std::cout << "Modo: Converter" << std::endl;
    std::cout << "Pasta: " << GetFolder() << std::endl;
    std::cout << "Filtro: " << GetFilter() << std::endl;
    std::cout << "De: " << m_FromFormat << std::endl;
    std::cout << "Para: " << m_ToFormat << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    const std::filesystem::path fromExtension = "." + formatToString(m_FromFormat);
    for (const std::filesystem::path &filepath : GetFiles(fromExtension))
    {
        std::cout << GetModeName() << "Convertendo " << filepath << std::endl;

        Image img{filepath, 3};
        img.convert(m_ToFormat);

        std::cout << GetModeName() << "Convertido com sucesso!\n\n";
    }

    std::cout << GetModeName() << "Arquivos convertidos com sucesso!" << std::endl;
}
