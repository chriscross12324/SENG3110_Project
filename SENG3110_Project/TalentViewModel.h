#pragma once
#include "TalentViewModel.g.h"
#include "TalentsSku.h"

namespace winrt::SENG3110_Project::implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel>
    {
        TalentViewModel();

        winrt::SENG3110_Project::TalentsSku TalentsSku();

    private:
        SENG3110_Project::TalentsSku m_talentSku{ nullptr };
    };
}
namespace winrt::SENG3110_Project::factory_implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel, implementation::TalentViewModel>
    {
    };
}
