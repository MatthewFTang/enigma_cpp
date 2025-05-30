// Copyright (C) 2024 The Author
#pragma once
#include <string>
#include <unordered_map>

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"
#include <memory>
class Application {
   public:
    Application();
    ~Application() = default;
    void Run();
    [[nodiscard]] bool ShouldQuit() const { return should_quit; }

   private:
    void WindowSelector();
    void ReflectorSelector();
    void RotorSelector();
    void TextInput();
    void ConfigureWithSettings();
    void PlugboardSettings();
    void DisplayCipher();
    void RunCracking();
    std::string IntToRoman(int rotor);
    std::string FormatMessageForMorse(const std::string& message);
    void ParsePlugboardSettings();
    void StyleGui();

    bool should_quit = false;
    int reflector_selection_ = 1;
    int window_selection_[3] = {0, 1, 2};
    int rotor_selection_[4] = {0, 1, 2, 3};
    std::unordered_map<char, char> plugboard_settings_;
    //char message_[1024];
    std::string message_ = "HELLO WORLD";
    std::string cipher_;
    std::string plugboard_message_ = "ab cd";
    Enigma enigma_;
    EnigmaSettings settings_;
    float top_settings_height_ = 150;
    float window_width_ = 800;
};
