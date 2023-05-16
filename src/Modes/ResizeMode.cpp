#include "ResizeMode.h"

// #define STB_IMAGE_IMPLEMENTATION
// #include <stb_image.h>
// #define STB_IMAGE_RESIZE_IMPLEMENTATION
// #include <stb_image_resize.h>
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include <stb_image_write.h>

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
    std::cout << GetModeName() << "Redimensionando " << filepath << std::endl;

    Image img{filepath};
    img.resize(newWidth, newHeight);

    std::cout << GetModeName() << "Redimensionada com sucesso!\n\n";
    // int width, height, numComps, numCompReq = 4;
    // if (unsigned char *data = stbi_load(filepath.string().c_str(), &width, &height, &numComps, 4))
    // {
    //     const int numOutputPixels = newWidth * newHeight * numCompReq;
    //     unsigned char outputData[numOutputPixels] = {0};

    //     const int resizeResult = stbir_resize_uint8(
    //         data, width, height, 0,
    //         outputData, newWidth, newHeight, 0, numCompReq);

    //     if (resizeResult == 0)
    //         std::cerr << GetModeName() << "Erro ao redimensionar " << filepath << std::endl;
    //     else
    //     {
    //         int writeResult = 1;

    //         const std::string extension = filepath.extension().string();
    //         if (extension == ".jpg")
    //         {
    //             writeResult = stbi_write_jpg(filepath.string().c_str(), newWidth, newHeight, numCompReq, outputData, 100);
    //         }
    //         else if (extension == ".png")
    //         {
    //             writeResult = stbi_write_png(filepath.string().c_str(), newWidth, newHeight, numCompReq, outputData, 0);
    //         }
    //         else
    //         {
    //             std::cerr << GetModeName() << "Formato " << extension << " não suportado!" << std::endl;
    //             return;
    //         }

    //         if (writeResult == 0)
    //             std::cerr << GetModeName() << "Erro ao escrever " << filepath << std::endl;

    //         stbi_image_free(data);
    //     }
    // }
    // else
    // {
    //     std::cerr << "Erro ao carregar imagem" << std::endl;
    // }
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