#pragma once
#include "TalentsSku.g.h"

namespace winrt::SENG3110_Project::implementation
{
    struct TalentsSku : TalentsSkuT<TalentsSku>
    {
        TalentsSku() = delete;

        TalentsSku(hstring const& fName, hstring const& lName, hstring const& jType, double const& jCost);
        hstring firstName();
        void firstName(hstring const& value);
        hstring lastName();
        void lastName(hstring const& value);
        hstring jobType();
        void jobType(hstring const& value);
        double jobCost();
        void jobCost(double value);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring talentFName;
        winrt::hstring talentLName;
        winrt::hstring talentJType;
        double talentJCost;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::SENG3110_Project::factory_implementation
{
    struct TalentsSku : TalentsSkuT<TalentsSku, implementation::TalentsSku>
    {
    };
}
