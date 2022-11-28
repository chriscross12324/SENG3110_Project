#include "pch.h"
#include "TalentCls.h"
#include "TalentCls.g.cpp"

namespace winrt::SENG3110_Project::implementation
{
    TalentCls::TalentCls(int16_t talentID, hstring const& talentFName, hstring const& talentLName, hstring const& jobType, double jobCost) :
        m_talentID{ talentID },
        m_talentFName{ talentFName.c_str() },
        m_talentLName{ talentLName.c_str() },
        m_jobType{ jobType.c_str() },
        m_jobCost{ jobCost } {}

    int16_t TalentCls::TalentID()
    {
        return int16_t{ m_talentID };
    }

    hstring TalentCls::TalentFName()
    {
        return hstring{ m_talentFName };
    }

    hstring TalentCls::TalentLName()
    {
        return hstring{ m_talentFName };
    }

    hstring TalentCls::JobType()
    {
        return hstring{ m_jobType };
    }

    double TalentCls::JobCost()
    {
        return double{ m_jobCost };
    }
}
