#include "pch.h"
#include "TalentViewModel.h"
#include "TalentViewModel.g.cpp"

namespace winrt::SENG3110_Project::implementation
{
    winrt::SENG3110_Project::TalentCls TalentViewModel::DefaultTalent()
    {
        m_defaultTalent = winrt::make<TalentCls>(000, L"Johny", L"Appleseed", L"", 0.0);
        return m_defaultTalent;
    }
}
