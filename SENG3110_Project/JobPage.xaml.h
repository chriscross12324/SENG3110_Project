// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "JobPage.g.h"
#include <winrt/impl/Microsoft.UI.Xaml.Controls.2.h>
#include <winrt/impl/Windows.UI.Xaml.Controls.0.h>
#include <list>

namespace winrt::SENG3110_Project::implementation
{
    struct JobPage : JobPageT<JobPage>
    {
        JobPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        winrt::SENG3110_Project::TalentViewModel ViewModel();

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void selectJob(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:
        winrt::SENG3110_Project::TalentViewModel m_viewModel{ nullptr };
    };
}

namespace winrt::SENG3110_Project::factory_implementation
{
    struct JobPage : JobPageT<JobPage, implementation::JobPage>
    {
    };
}


