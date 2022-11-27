#include "pch.h"
#include "TalentViewModel.h"
#include "TalentViewModel.g.cpp"

namespace winrt::SENG3110_Project::implementation
{
    TalentViewModel::TalentViewModel()
    {
        m_talentSku = winrt::make<SENG3110_Project::implementation::TalentsSku>(L"Atticus");
    }

    winrt::SENG3110_Project::TalentsSku TalentViewModel::TalentsSku()
    {
        return m_talentSku;
    }
}
