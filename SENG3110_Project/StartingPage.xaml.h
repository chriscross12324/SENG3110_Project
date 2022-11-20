// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "StartingPage.g.h"

namespace winrt::SENG3110_Project::implementation
{
    struct StartingPage : StartingPageT<StartingPage>
    {
        StartingPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SENG3110_Project::factory_implementation
{
    struct StartingPage : StartingPageT<StartingPage, implementation::StartingPage>
    {
    };
}
