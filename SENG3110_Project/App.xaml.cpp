// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include <tchar.h>
#include <winuser.h>
#include <Windows.h>

using namespace winrt::Windows::UI;

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace SENG3110_Project;
using namespace SENG3110_Project::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const& e)
{
    window = make<MainWindow>();
    window.Activate();
    
    //Set Window Title
    HWND w = FindWindow(0, _T("WinUI Desktop"));
    SetWindowTextA(w, "Repairly");

    //Set WIndow Icon
    /*WindowId windowId = GetWindowIdFromWindow();
    AppWindow appWindow = AppWindow.GetFromWindowId(windowId);*/

    Frame rootFrame{ nullptr };
    auto content = window.Content();
    if (content) rootFrame = content.try_as<Frame>();

    rootFrame.Navigate(xaml_typename<SENG3110_Project::StartingPage>(), box_value(e.Arguments()));
}
