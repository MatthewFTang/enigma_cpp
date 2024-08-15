#include "Rotors.h"

#include <string>

Rotors::Rotors(std::string rotor) {
    if (rotor == "1") {
        wiring_ = I_wiring;
        turnover_ = I_turnover;
    } else if (rotor == "2") {
        wiring_ = II_wiring;
        turnover_ = II_turnover;
    } else if (rotor == "3") {
        wiring_ = III_wiring;
        turnover_ = III_turnover;
    }
    current_position_ = 0;
};

std::string Rotors::Enter(std::string character) {
    std::string alphabet = "ABCDEFGHIJKLMNOPKRSTQUVWXYZ";
    auto character_pos = alphabet.find(character);
    auto pos = (character_pos + current_position_) % 26;

    current_position_++;
    return std::to_string(wiring_[pos]);
}
