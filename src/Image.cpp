#include "Image.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image_resize.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

std::string formatToString(Image::Format format)
{
    switch (format)
    {
    case Image::Format::JPG:
        return "jpg";
    case Image::Format::PNG:
        return "png";
    default:
        return "";
    }
}

std::ostream &operator<<(std::ostream &out, Image::Format format)
{
    out << formatToString(format);
    return out;
}

Image::Image(const std::filesystem::path &filepath, int reqComps)
    : m_filepath{filepath}, m_reqComps{reqComps}
{
    m_data = stbi_load(filepath.string().c_str(), &m_width, &m_height, &m_numComps, m_reqComps);
}

Image::~Image()
{
    stbi_image_free(m_data);
}

bool Image::verifyData() const
{
    if (m_data == nullptr)
        return false;
    return true;
}

void Image::writeFile(const std::filesystem::path &filepath, Image::Format format) const
{
    int writeResult;
    switch (format)
    {
    case Image::Format::JPG:
        writeResult = stbi_write_jpg(filepath.string().c_str(), m_width, m_height, m_reqComps, m_data, 100);
        break;
    case Image::Format::PNG:
        writeResult = stbi_write_png(filepath.string().c_str(), m_width, m_height, m_reqComps, m_data, 0);
        break;
    default:
        std::cerr << "Formato não suportado!" << std::endl;
        break;
    }

    if (writeResult == 0)
        std::cerr << "Erro ao escrever " << filepath << std::endl;
}

void Image::convert(Format toFormat)
{
    if (!verifyData())
    {
        std::cerr << "Erro ao ler " << m_filepath << std::endl;
        return;
    }

    std::filesystem::path newFilepath = m_filepath;
    newFilepath.replace_extension(toFormat == Format::JPG ? ".jpg" : ".png");

    writeFile(newFilepath, toFormat);
}

void Image::resize(int width, int height)
{
    if (!verifyData())
    {
        std::cerr << "Erro ao ler " << m_filepath << std::endl;
        return;
    }

    const int numOutputPixels = width * height * m_reqComps;
    unsigned char outputData[numOutputPixels] = {0};

    const int resizeResult = stbir_resize_uint8(
        m_data, m_width, m_height, 0,
        outputData, width, height, 0, m_reqComps);

    if (resizeResult == 0)
        std::cerr << "Erro ao redimensionar " << m_filepath << std::endl;
    else
    {
        m_width = width;
        m_height = height;
        m_data = (unsigned char *)realloc(m_data, numOutputPixels);
        memcpy(m_data, outputData, numOutputPixels);
    }

    writeFile(m_filepath, Format::PNG);
}

void Image::scale(float amount)
{
    resize(m_width * amount, m_height * amount);
}
