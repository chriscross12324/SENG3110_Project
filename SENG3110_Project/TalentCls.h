#pragma once
#include "TalentCls.g.h"

namespace winrt::SENG3110_Project::implementation
{
    struct TalentCls : TalentClsT<TalentCls>
    {
        TalentCls() = default;

        TalentCls(int16_t talentID, hstring const& talentFName, hstring const& talentLName, hstring const& jobType, double jobCost);
        int16_t TalentID();
        hstring TalentFName();
        hstring TalentLName();
        hstring JobType();
        double JobCost();

    private:
        std::int16_t m_talentID;
        std::wstring m_talentFName;
        std::wstring m_talentLName;
        std::wstring m_jobType;
        double m_jobCost;
    };
}
namespace winrt::SENG3110_Project::factory_implementation
{
    struct TalentCls : TalentClsT<TalentCls, implementation::TalentCls>
    {
    };
}
