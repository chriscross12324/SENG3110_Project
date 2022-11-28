#pragma once
#include "TalentViewModel.g.h"
#include "TalentCls.h"

namespace winrt::SENG3110_Project::implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel>
    {
        TalentViewModel();

        winrt::SENG3110_Project::TalentCls DefaultTalent();
        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Talents();

    private:
        SENG3110_Project::TalentCls m_defaultTalent{ nullptr };
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable>m_talents;
    };
}
namespace winrt::SENG3110_Project::factory_implementation
{
    struct TalentViewModel : TalentViewModelT<TalentViewModel, implementation::TalentViewModel>
    {
    };
}
