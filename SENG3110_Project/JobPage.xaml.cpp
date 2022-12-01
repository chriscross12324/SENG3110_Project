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
    vector<Talent> Talents;

    JobPage::JobPage()
    {
        InitializeComponent();
        m_viewModel = winrt::make<TalentViewModel>();
        talentList = talentList.getTalents();
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
        //Clear Talents list
        Talents.clear();

        //Regenerate LinkedList
        //m_viewModel = winrt::make<TalentViewModel>();
        talentList = talentList.getTalents();

        // Get Selected Item String
        MenuFlyoutItem item = winrt::unbox_value<MenuFlyoutItem>(sender);
        string menuItemContent = winrt::to_string(item.Text());

        //Convert String to WString
        wstring wstr(menuItemContent.begin(), menuItemContent.end());

        //Set DropDownButton Text
        jobSelectionMenu().Content(box_value(wstr));

        //Convert Linked List to List
        talentList.insertionSort(talentList.head, menuItemContent);
        Sleep(1);
        Talents = talentList.convertLinkedList(talentList.head);
        ViewModel().Talents().Clear();

        for (int i = 0; i < Talents.size(); i++) {
            Talent tal = Talents[i];
            winrt::hstring fName = winrt::to_hstring(tal.firstName);
            winrt::hstring lName = winrt::to_hstring(tal.lastName);
            winrt::hstring jType = winrt::to_hstring(menuItemContent);
            ViewModel().Talents().Append(winrt::make<TalentCls>(tal.userID, fName, lName, jType, tal.getJobCost(menuItemContent)));
        }
    }
}







