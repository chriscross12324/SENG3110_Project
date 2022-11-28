#pragma once
#include "TalentViewModel.g.h"
#include "TalentCls.h"

namespace winrt::SENG3110_Project::implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel>
    {
        TalentViewModel() = default;

        winrt::SENG3110_Project::TalentCls DefaultTalent();

    private:
        SENG3110_Project::TalentCls m_defaultTalent{ nullptr };
    };
}
namespace winrt::SENG3110_Project::factory_implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel, implementation::TalentViewModel>
    {
    };
}
