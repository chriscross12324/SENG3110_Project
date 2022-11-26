// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "JobPage.xaml.h"
#include <string>
#include <winrt/Windows.UI.Xaml.Interop.h>
#if __has_include("JobPage.g.cpp")
#include "JobPage.g.cpp"
#endif
using namespace std;
using namespace winrt::Microsoft::UI::Xaml::Controls;

using namespace winrt;
using namespace Microsoft::UI::Xaml;

template <typename T>
inline winrt::Windows::UI::Xaml::Interop::TypeName xaml_typename();

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::SENG3110_Project::implementation
{
    JobPage::JobPage()
    {
        InitializeComponent();
    }

    int32_t JobPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void JobPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void JobPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        this->Frame().GoBack();
    }

    void JobPage::selectCarpenter(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Carpenter"));
    }

    void JobPage::selectElectrician(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Electrician"));
    }

    void JobPage::selectFloorer(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Floorer"));
    }

    void JobPage::selectPainter(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Painter"));
    }

    void JobPage::selectPlumber(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Plumber"));
    }

    void JobPage::selectPoolCleaner(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Pool Cleaner"));
    }

    void JobPage::selectRoofer(IInspectable const&, RoutedEventArgs const&)
    {
        jobSelectionMenu().Content(box_value(L"Roofer"));
    }
}
