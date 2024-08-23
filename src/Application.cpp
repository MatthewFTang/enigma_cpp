#include "Application.h"

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"
#include "imgui.h"

void Application::TextInput() {
    /*ImGui::ShowDemoWindow();*/

    static char text[1024 * 16] = "Input your text here";

    static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
    ImGui::SeparatorText("MESSAGE TEXT");
    ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text),
                              ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16),
                              flags);
}

void Application::AlignForWidth(float width, float alignment) {
    ImGuiStyle& stAyle = ImGui::GetStyle();
    float avail = ImGui::GetContentRegionAvail().x;
    float off = (avail - width) * alignment;
    if (off > 0.0f) ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
}

void Application::WindowSelection(const char* window_value) {
    int item_selected_idx = 0;  // Here we store our selection data as an index.

    const char* combo_preview_value = window_value;

    if (ImGui::BeginCombo(window_value, combo_preview_value)) {
        for (int n = 0; n < 26; n++) {
            const bool is_selected = (item_selected_idx == n);
            const char c = n + 'A';
            if (ImGui::Selectable(&c, is_selected)) item_selected_idx = n;
        }
        ImGui::EndCombo();
    }
}

void Application::RotorSelector() {
    ImGui::BeginChild("outer_child", ImVec2(0, ImGui::GetFontSize() * 20.0f),
                      ImGuiChildFlags_Border);
    ImGui::PushItemWidth(80);
    const char* items[] = {"I", "II", "III", "IV", "V"};
    AlignForWidth(300);
    ImGui::Text("Rotors");
    AlignForWidth(300);
    static int selection[4] = {0, 1, 2, 3};
    for (int i = 0; i < 3; i++) {
        if (i > 0) ImGui::SameLine();
        ImGui::PushID(i);
        ImGui::ListBox("", &selection[i], items, IM_ARRAYSIZE(items));
        ImGui::PopID();
    }
    ImGui::PopItemWidth();
    ImGui::EndChild();
}

void Application::Run() {
    EnigmaSettings settings;
    Enigma enigma;

    ImGui::AlignTextToFramePadding();
    ImGui::Text("Engima simualtor");  // Display a simple label
    RotorSelector();
    auto* left = "Left";
    WindowSelection(left);
    auto* right = "Right";
    WindowSelection(right);
    auto* middle = "Middle";
    WindowSelection(middle);
    TextInput();
}
