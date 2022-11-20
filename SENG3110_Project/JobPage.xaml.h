// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "JobPage.g.h"

namespace winrt::SENG3110_Project::implementation
{
    struct JobPage : JobPageT<JobPage>
    {
        JobPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SENG3110_Project::factory_implementation
{
    struct JobPage : JobPageT<JobPage, implementation::JobPage>
    {
    };
}
