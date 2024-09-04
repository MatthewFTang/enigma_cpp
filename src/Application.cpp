#include "Application.h"

#include <iostream>
#include <ostream>
#include <string>

#include "imgui.h"
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
    ImVec4(0.70f, 0.70f, 0.90f, 0.60f);
    ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] =
        ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] =
        ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
}
void Application::TextInput() {
    /*ImGui::ShowDemoWindow();*/
    ImGui::BeginChild("text", {600, 300});
    static char text[1024 * 16] = "Input your text here";

    static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
    ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text),
                              ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16),
                              flags);
    ImGui::EndChild();
}

// Demonstrate create a window with multiple child windows.
void Application::AlignForWidth(float width, float alignment) {
    ImGuiStyle& stAyle = ImGui::GetStyle();
    float avail = ImGui::GetContentRegionAvail().x;
    float off = (avail - width) * alignment;
    if (off > 0.0f) ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
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
    static bool menu = false;

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
void Application::Run() {
    ImGui::SetNextWindowSize({800, 900});
    ImGui::Begin("Enigma simulator", nullptr,
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    auto window_position = ImGui::GetWindowPos();
    auto window_size = ImGui::GetWindowSize();
    /*ImGui::SeparatorText("Settings");*/
    ImGui::SeparatorText("Settings");

    RotorSelector();
    ImGui::SameLine();
    WindowSelector();
    ImGui::SameLine();
    ReflectorSelector();
    ImGui::SeparatorText("Input message");
    TextInput();
    if (ImGui::Button("Quit")) {
        should_quit = true;
    }
    std::cout << reflector_selection_ << std::endl;
    ImGui::End();
}
