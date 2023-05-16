#include "ScaleMode.h"

ScaleMode::ScaleMode(const std::string &filter, const std::string &folder,
                     float scaleFactor)
    : ResizeMode{filter, folder}, m_ScaleFactor{scaleFactor}
{
}

const std::string &ScaleMode::GetModeName() const
{
    static const std::string scaleModeName = "[Scale]: ";
    return scaleModeName;
}

void ScaleMode::RunImpl()
{
    std::cout << "-----------------PHOTOBATCH-----------------" << std::endl;
    std::cout << "Modo: Escalonar" << std::endl;
    std::cout << "Pasta: " << GetFolder() << std::endl;
    std::cout << "Filtro: " << GetFilter() << std::endl;
    std::cout << "Fator: " << m_ScaleFactor << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (std::filesystem::path &filepath : GetFiles())
    {
        std::cout << GetModeName() << "Escalando " << filepath << std::endl;

        Image img{filepath};
        img.scale(m_ScaleFactor);

        std::cout << GetModeName() << "Escalonado com sucesso!\n\n";
        // int width, height;
        // stbi_info(filepath.string().c_str(), &width, &height, nullptr);

        // const int newWidth = width * m_ScaleFactor;
        // const int newHeight = height * m_ScaleFactor;
        // std::cout << GetModeName() << "Nova dimensão da imagem " << newWidth << "x" << newHeight << std::endl;

        // ResizeImage(filepath, newWidth, newHeight);
    }
}