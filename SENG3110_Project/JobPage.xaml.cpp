// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "JobPage.xaml.h"
#if __has_include("JobPage.g.cpp")
#include "JobPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

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
        myButton().Content(box_value(L"Clicked"));

    }
}
