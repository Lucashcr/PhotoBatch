#pragma once

#include "Mode.h"

class RenameMode final : public Mode
{
public:
    RenameMode(const std::string &filter, const std::string &folder, const std::string &preffix, int startNumber);

    const std::string &GetModeName() const override;

protected:
    void RunImpl() override;

private:
    std::string m_Preffix;
    int m_StartNumber;
};
