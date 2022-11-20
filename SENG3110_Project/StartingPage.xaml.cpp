// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "StartingPage.xaml.h"
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Microsoft.UI.Xaml.Media.Animation.h>
//#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#if __has_include("StartingPage.g.cpp")
#include "StartingPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

template <typename T>
inline winrt::Windows::UI::Xaml::Interop::TypeName xaml_typename();

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::SENG3110_Project::implementation
{
    StartingPage::StartingPage()
    {
        InitializeComponent();
        //this->SetTitleBar(titleBar());
        /*this->ExtendsContentIntoTitleBar(true);
        this->SetTitleBar(titleBar());*/
    }

    int32_t StartingPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void StartingPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void StartingPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        loginButton().Content(box_value(L"Logging In"));

        //Navigate to Job Page
        this->Frame().Navigate(xaml_typename<JobPage>(), nullptr, Microsoft::UI::Xaml::Media::Animation::DrillInNavigationTransitionInfo());
    }
}
