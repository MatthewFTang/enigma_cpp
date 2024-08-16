

#include <unordered_map>
class Plugboard {
   public:
    Plugboard() = default;
    Plugboard(std::unordered_map<char, char> mapping)
        : plugboard_settings_(mapping){};
    char SwapLetter(char c);

   private:
    std::unordered_map<char, char> plugboard_settings_;
};
