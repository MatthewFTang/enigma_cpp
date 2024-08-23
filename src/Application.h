
#pragma once

class Application {
   public:
    Application() = default;
    void Run();

   private:
    void AlignForWidth(float width, float alignment = 0.5f);
    void WindowSelection(const char* window_value);
    void RotorSelector();
    void TextInput();
};
