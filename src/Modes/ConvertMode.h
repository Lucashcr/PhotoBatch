#pragma once

#include "Mode.h"

class ConvertMode final : public Mode
{

public:
    ConvertMode(const std::string &filter, const std::string &folder, Image::Format fromFormat, Image::Format toFormat);

    const std::string &GetModeName() const override;

protected:
    void RunImpl() override;

private:
    Image::Format m_FromFormat;
    Image::Format m_ToFormat;
};