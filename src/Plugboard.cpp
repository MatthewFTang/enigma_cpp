#include "Plugboard.hpp"

char Plugboard::SwapLetter(char c) {
    auto it = plugboard_settings_.find(c);
    if (it != plugboard_settings_.end()) {
        return it->second;
    }
    return c;
}
