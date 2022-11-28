// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.
#include "pch.h"
#include "JobPage.xaml.h"
#include <string>
#include <list>
#include <winrt/Windows.UI.Xaml.Interop.h>
#if __has_include("JobPage.g.cpp")
#include "JobPage.g.cpp"
#endif
#include <Talent.h>
#include "TalentViewModel.h"

using namespace std;
using namespace winrt::Microsoft::UI::Xaml::Controls;

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace SENG3110_Project;

template <typename T>
inline winrt::Windows::UI::Xaml::Interop::TypeName xaml_typename();

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::SENG3110_Project::implementation
{
    TalentLinkedList talentList;
    list<Talent> Talents;

    JobPage::JobPage()
    {
        InitializeComponent();
        m_viewModel = winrt::make<TalentViewModel>();
	    
        
        //talentList.getTalents();
    }

    int32_t JobPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void JobPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::SENG3110_Project::TalentViewModel JobPage::ViewModel()
    {
        return m_viewModel;
    }

    void JobPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        this->Frame().GoBack();
    }

    void JobPage::selectJob(IInspectable const& sender, RoutedEventArgs const&)
    {
        // Get Selected Item String
        MenuFlyoutItem item = winrt::unbox_value<MenuFlyoutItem>(sender);
        string menuItemContent = winrt::to_string(item.Text());

        //Convert String to WString
        wstring wstr(menuItemContent.begin(), menuItemContent.end());

        //Set DropDownButton Text
        jobSelectionMenu().Content(box_value(wstr));

        //Convert Linked List to List
        Talents = talentList.convertLinkedList(talentList.sorted);
        ViewModel().Talents().Clear();

        //ViewModel().Talents().Append(winrt::make<TalentCls>(000, L"Johny", L"Appleseed", L"", 0.0));

        /*int i = 0;
        list<Talent>::iterator it = Talents.begin();
        while (Talents.size() > i) {
            advance(it, 1);
            Talent tal = *it;
            string name = tal.firstName;
            ViewModel().Talents().Append(winrt::make<TalentCls>(000, L"tal.firstName", L"tal.lastName", L"menuItemContent", 0.0));
            i++;
        }*/

        for (int i = 0; i < 5; i++) {
            ViewModel().Talents().Append(winrt::make<TalentCls>(Talents.size(), L"fName", L"lName", L"jType", 0.0));
        }
    }
}







