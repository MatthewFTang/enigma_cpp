// Copyright (C) 2024 The Author
#pragma once
#include <string>

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"
class Application {
   public:
    Application();
    ~Application() = default;
    void Run();
    bool ShouldQuit() const { return should_quit; }

   private:
    void WindowSelector();
    void ReflectorSelector();
    void RotorSelector();
    void TextInput();
    void ConfigureWithSettings();
    void DisplayCipher();
    std::string IntToRoman(int rotor);
    std::string FormatMessageForMorse(const std::string& message);

    bool should_quit = false;
    int reflector_selection_ = 1;
    int window_selection_[3] = {0, 1, 2};
    int rotor_selection_[4] = {0, 1, 2, 3};
    char message_[1024 * 16];
    std::string cipher_;
    Enigma enigma_;
    EnigmaSettings settings_;
};
