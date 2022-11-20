// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "MainWindow.xaml.h"
#include <winrt/Windows.UI.Xaml.Interop.h>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <StartingPage.xaml.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

template <typename T>
inline winrt::Windows::UI::Xaml::Interop::TypeName xaml_typename();

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.



namespace winrt::SENG3110_Project::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        
        //Set TitleBar Icon and Text
        //auto hWnd = WinRT::Interop::WindowNative::GetWindowHandle(this);
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
