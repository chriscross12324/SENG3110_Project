#include "pch.h"
#include "TalentsSku.h"
#include "TalentsSku.g.cpp"

namespace winrt::SENG3110_Project::implementation
{
    TalentsSku::TalentsSku(hstring const& fName, hstring const& lName, hstring const& jType, double const& jCost) : talentFName{ fName }, talentLName{ lName }, talentJType{ jType }, talentJCost{ jCost }
    {
    }

    hstring TalentsSku::firstName()
    {
        return talentFName;
    }
    void TalentsSku::firstName(hstring const& value)
    {
        if (talentFName != value) {
            talentFName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"firstName" });
        }
    }


    hstring TalentsSku::lastName()
    {
        return talentLName;
    }
    void TalentsSku::lastName(hstring const& value)
    {
        if (talentLName != value) {
            talentLName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"lastName" });
        }
    }


    hstring TalentsSku::jobType()
    {
        return talentJType;
    }
    void TalentsSku::jobType(hstring const& value)
    {
        if (talentJType != value) {
            talentJType = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"jobType" });
        }
    }


    double TalentsSku::jobCost()
    {
        return talentJCost;
    }
    void TalentsSku::jobCost(double value)
    {
        if (talentJCost != value) {
            talentJCost = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"jobCost" });
        }
    }


    winrt::event_token TalentsSku::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void TalentsSku::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
