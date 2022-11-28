#include "pch.h"
#include "TalentViewModel.h"
#include "TalentViewModel.g.cpp"
#include <Talent.h>

namespace winrt::SENG3110_Project::implementation
{
    winrt::SENG3110_Project::TalentCls TalentViewModel::DefaultTalent()
    {
        m_defaultTalent = winrt::make<TalentCls>(000, L"Johny", L"Appleseed", L"", 0.0);
        return m_defaultTalent;
    }

    TalentViewModel::TalentViewModel()
    {
        std::vector<Windows::Foundation::IInspectable> talents;
        TalentLinkedList talentList;
        
        talents.push_back(winrt::make<TalentCls>(000, L"Johny", L"Appleseed", L"", 0.0));
        talents.push_back(winrt::make<TalentCls>(001, L"Adam", L"Kim", L"", 0.0));
        talents.push_back(winrt::make<TalentCls>(002, L"Spencer", L"Qou", L"", 0.0));
        talents.push_back(winrt::make<TalentCls>(003, L"Grtj", L"Puqa", L"", 0.0));
        talents.push_back(winrt::make<TalentCls>(004, L"Opa", L"Ol", L"", 0.0));

        m_talents = winrt::single_threaded_observable_vector<Windows::Foundation::IInspectable>(std::move(talents));
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> TalentViewModel::Talents()
    {
        return m_talents;
    }
}
