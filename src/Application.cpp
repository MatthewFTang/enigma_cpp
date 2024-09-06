// Copyright (C) 2024 The Author
#include "Application.h"

#include <cstring>
#include <iostream>
#include <string>

#include "../imgui/imgui.h"
Application::Application() {
    ImGui::StyleColorsDark();
    auto& style = ImGui::GetStyle();
    style.WindowRounding = 10.0f;
    style.FrameRounding = 10.0f;
    style.WindowTitleAlign = {0.5f, 0.5f};
    auto& io = ImGui::GetIO();
    io.FontDefault =
        io.Fonts->AddFontFromFileTTF("assets/fonts/test.ttf", 28.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.01f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
    style.Colors[ImGuiCol_TitleBgCollapsed] =
        ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] =
        ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] =
        ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
    style.Colors[ImGuiCol_SliderGrabActive] =
        ImVec4(0.30f, 0.30f, 0.30f, 0.84f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
    style.Colors[ImGuiCol_ResizeGripHovered] =
        ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
    style.Colors[ImGuiCol_ResizeGripActive] =
        ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] =
        ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] =
        ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
}
void Application::TextInput() {
    ImGui::BeginChild("text", {1200, 200});
    static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
    ImGui::InputTextMultiline("adf", &message_[0], IM_ARRAYSIZE(message_),
                              {1200, 200}, flags);
    ImGui::EndChild();
}

void Application::RotorSelector() {
    ImGui::BeginChild("left", {250, 200});
    ImGui::PushItemWidth(80);
    const char* items[] = {"I", "II", "III", "IV", "V"};
    ImGui::Text("Rotors");
    for (int i = 0; i < 3; i++) {
        if (i > 0) ImGui::SameLine();
        ImGui::PushID(i);
        ImGui::ListBox("", &rotor_selection_[i], items, IM_ARRAYSIZE(items));
        ImGui::PopID();
    }
    ImGui::PopItemWidth();
    ImGui::EndChild();
}
void Application::WindowSelector() {
    ImGui::BeginChild("center", {250, 200});
    ImGui::PushItemWidth(80);
    const char* items[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                           "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                           "S", "T", "U", "V", "W", "X", "Y", "Z"};
    ImGui::Text("Window");
    ImGui::NewLine();

    for (int i = 0; i < 3; i++) {
        ImGui::SameLine();
        ImGui::PushID(i);
        ImGui::ListBox("", &window_selection_[i], items, IM_ARRAYSIZE(items));

        ImGui::PopID();
    }
    ImGui::EndChild();
}
void Application::ReflectorSelector() {
    ImGui::BeginChild("right", {120, 200});
    const char* items[] = {"A", "B", "C"};
    ImGui::Text("Reflector");
    ImGui::ListBox(" ", &reflector_selection_, items, IM_ARRAYSIZE(items));
    ImGui::EndChild();
}
void Application::ConfigureWithSettings() {
    settings_.rotor_l = IntToRoman(rotor_selection_[0]);
    settings_.rotor_m = IntToRoman(rotor_selection_[1]);
    settings_.rotor_r = IntToRoman(rotor_selection_[2]);
    settings_.window_setting_l = static_cast<char>(window_selection_[0] + 'A');
    settings_.window_setting_m = static_cast<char>(window_selection_[1] + 'A');
    settings_.window_setting_r = static_cast<char>(window_selection_[2] + 'A');
    settings_.plugboard = {};
    settings_.reflector = static_cast<char>(reflector_selection_ + 'A');
    std::cout << "settings >>" << settings_.window_setting_l << " "
              << settings_.window_setting_m << " " << settings_.window_setting_r
              << std::endl;
    enigma_ = Enigma();
    enigma_.Configure(settings_);
    auto message = std::string(message_);
    cipher_ = enigma_.Encode(message);
}

void Application::DisplayCipher() {
    ImGui::BeginChild("cipher", {1200, 200});
    ImGui::Text("%s", FormatMessageForMorse(cipher_).c_str());
    ImGui::EndChild();
}
void Application::Run() {
    ImGui::SetNextWindowSize({1280, 1200});
    ImGui::SetNextWindowPos({0, 0});
    ImGui::Begin("Enigma simulator", nullptr,
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    ImGui::BeginGroup();
    ImGui::SeparatorText("Settings");

    RotorSelector();
    ImGui::SameLine();
    WindowSelector();
    ImGui::SameLine();
    ReflectorSelector();
    ImGui::SeparatorText("Input message");
    TextInput();

    if (ImGui::Button("Encrypt")) {
        ConfigureWithSettings();
    }
    DisplayCipher();
    if (ImGui::Button("Quit")) {
        should_quit = true;
    }
    ImGui::EndGroup();
    ImGui::End();
}
std::string Application::IntToRoman(int rotor) {
    switch (rotor) {
        case (0):
            return "I";
        case (1):
            return "II";
        case (2):
            return "III";
        case (3):
            return "IV";
        case (4):
            return "V";
        default:
            return "I";
    }
}
std::string Application::FormatMessageForMorse(const std::string& message) {
    std::string new_message;

    for (int i = 0; i < message.size(); i++) {
        if (i > 0 && i % 5 == 0) {
            new_message += " ";
        }
        new_message += message[i];
    }
    return new_message;
}
