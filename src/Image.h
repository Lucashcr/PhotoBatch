#pragma once

#include <filesystem>
#include <vector>

class Image
{
public:
    enum class Format
    {
        JPG,
        PNG
    };

    Image(const std::filesystem::path &filepath);
    ~Image();

    void convert(Format toFormat);
    void resize(int width, int height);
    void scale(float amount);

private:
    int m_width;
    int m_height;
    int m_numComps;
    unsigned char *m_data;
    std::filesystem::path m_filepath;

    bool verifyData() const;
    void writeFile(const std::filesystem::path &filepath, Format format) const;
};

std::string formatToString(Image::Format format);
std::ostream &operator<<(std::ostream &out, Image::Format format);
