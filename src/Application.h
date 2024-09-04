// Copyright (C) 2024 The Author
#pragma once

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"

class Application {
   public:
    Application();
    void Run();
    bool ShouldQuit() { return should_quit; }

   private:
    void AlignForWidth(float width, float alignment = 0.5f);
    void WindowSelector();
    void ReflectorSelector();
    void RotorSelector();
    void TextInput();
    bool should_quit = false;
    void CenteredSeparatorText(const char* text);
    int reflector_selection_ = 0;
    int window_selection_[3] = {0, 1, 2};
    int rotor_selection_[4] = {0, 1, 2, 3};

    Enigma enigma_;
    EnigmaSettings settings_;
};
