// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "StartingPage.xaml.h"
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Microsoft.UI.Xaml.Media.Animation.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#if __has_include("StartingPage.g.cpp")
#include "StartingPage.g.cpp"
#endif
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace std;

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

    void StartingPage::buttonCreateAccountClick(IInspectable const&, RoutedEventArgs const&) {
        const auto firstNameInput = createAccountFNameInput();
        const auto lastNameInput = createAccountLNameInput();
        const auto emailInput = createAccountEmailInput();
        const auto pinInput = createAccountPinInput();
        const auto confirmPinInput = createAccountConfirmPinInput();
        
        //Inputs
        string userFName = winrt::to_string(firstNameInput.Text());
        string userLName = winrt::to_string(lastNameInput.Text());
        string userEmail = winrt::to_string(emailInput.Text());
        string userPassword = winrt::to_string(pinInput.Password());
        string userConfirmPassword = winrt::to_string(confirmPinInput.Password());

        if (userPassword == userConfirmPassword) {
            fstream accountFile;
            accountFile.open("userAccounts.txt", ios_base::app);
            //accountFile.seekg(accountFile.tellg(), std::ios::end);

            if (accountFile.is_open()) {
                accountFile << (rand() % 899 + 100) << "~" << userFName << "~" << userLName << "~" << userEmail << "~" << userPassword <<endl;
                accountFile.close();
                createAccountButton().Content(box_value(L"Created"));
            }
            else {
                cout << "Failed to open file";
                createAccountButton().Content(box_value(L"Failed"));
            }
        }
    }

    void StartingPage::buttonLoginClick(IInspectable const&, RoutedEventArgs const&) {
        const auto emailInput = loginEmailInput();
        const auto pinInput = loginPinInput();

        //Inputs
        string userEmail = winrt::to_string(emailInput.Text());
        string userPassword = winrt::to_string(pinInput.Password());

        ifstream accountFile;
        string line = "";
        bool userMatch = false;
        accountFile.open("userAccounts.txt", ios_base::app);
        //accountFile.seekg(accountFile.tellg(), std::ios::end);

        if (accountFile.is_open()) {
            while (getline(accountFile, line) && userMatch == false) {
                std::vector<std::string> userInfo;
                std::string token;
                std::stringstream ss(line);

                while (getline(ss, token, '~')) {
                    userInfo.push_back(token);
                }

                if (userEmail == userInfo[3] && userPassword == userInfo[4]) {
                    this->Frame().Navigate(xaml_typename<JobPage>(), nullptr, Microsoft::UI::Xaml::Media::Animation::DrillInNavigationTransitionInfo());
                }
            }
            accountFile.close();
        }
        else {
            cout << "Failed to open file";
            loginButton().Content(box_value(L"Failed"));
        }
    }
}
