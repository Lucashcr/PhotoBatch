#include "ResizeMode.h"

ResizeMode::ResizeMode(const std::string &filter, const std::string &folder, int width, int height)
    : Mode{filter, folder}, m_Width{width}, m_Height{height}
{
}

const std::string &ResizeMode::GetModeName() const
{
    static std::string resizeModeName = "[Resize]: ";
    return resizeModeName;
}

void ResizeMode::ResizeImage(const std::filesystem::path &filepath, int newWidth, int newHeight) const
{
    Image img{filepath, 4};
    img.resize(newWidth, newHeight);

    std::cout << GetModeName() << "Redimensionada com sucesso!\n\n";
}

void ResizeMode::RunImpl()
{
    std::cout << "-----------------PHOTOBATCH-----------------" << std::endl;
    std::cout << "Modo: Redimensionar" << std::endl;
    std::cout << "Pasta: " << GetFolder() << std::endl;
    std::cout << "Filtro: " << GetFilter() << std::endl;
    std::cout << "Largura: " << m_Width << std::endl;
    std::cout << "Altura: " << m_Height << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (std::filesystem::path &filepath : GetFiles())
    {
        std::cout << GetModeName() << "Redimensionando " << filepath.filename() << std::endl;
        try
        {
            ResizeImage(filepath, m_Width, m_Height);
            std::cout << GetModeName() << filepath.filename() << " redimensionada com sucesso!" << std::endl;
        }
        catch (std::exception &exception)
        {
            std::cout << GetModeName() << "Erro ao redimensionar " << filepath.filename() << std::endl
                      << exception.what() << std::endl;
        }
    }

    std::cout << GetModeName() << "Arquivos redimensionados com sucesso!" << std::endl;
}