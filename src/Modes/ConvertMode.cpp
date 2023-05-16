#include "ConvertMode.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

std::string formatToString(ConvertMode::Format format)
{
    switch (format)
    {
    case ConvertMode::Format::JPG:
        return "jpg";
    case ConvertMode::Format::PNG:
        return "png";
    default:
        return "";
    }
}

std::ostream &operator<<(std::ostream &out, ConvertMode::Format format)
{
    out << formatToString(format);
    return out;
}

ConvertMode::ConvertMode(const std::string &filter, const std::string &folder, Format fromFormat, Format toFormat)
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
    std::cout << "From format: " << m_FromFormat << std::endl;
    std::cout << "To format: " << m_ToFormat << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    const std::filesystem::path fromExtension = "." + formatToString(m_FromFormat);
    for (const std::filesystem::path &filepath : GetFiles(fromExtension))
    {
        std::cout << GetModeName() << "Convertendo " << filepath << std::endl;

        int width, height, numComps, numReqComp = 3;

        if (unsigned char *data = stbi_load(filepath.string().c_str(), &width, &height, &numComps, numReqComp))
        {
            std::filesystem::path destinyFilepath = filepath;
            destinyFilepath.replace_extension(formatToString(m_ToFormat));

            int writeResult = 0;
            switch (m_ToFormat)
            {
            case Format::JPG:
                writeResult = stbi_write_jpg(destinyFilepath.string().c_str(), width, height, numReqComp, data, 100);
                break;
            case Format::PNG:
                writeResult = stbi_write_png(destinyFilepath.string().c_str(), width, height, numReqComp, data, 0);
                break;
            default:
                break;
            }

            if (writeResult == 0)
                std::cerr << GetModeName() << "Erro ao converter " << filepath << std::endl;
            else
                std::cout << GetModeName() << "Convertido com sucesso para " << destinyFilepath << std::endl;

            stbi_image_free(data);
        }
        else
        {
            std::cerr << GetModeName() << "Erro ao carregar " << filepath << std::endl;
        }
    }

    std::cout << GetModeName() << "Arquivos convertidos com sucesso!" << std::endl;
}
