#include "Rotors.hpp"

#include <string>

#include "Enigma.hpp"

Rotors::Rotors(std::string rotor, std::string window_position, Rotors* _next) {
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

    if (_next != nullptr)
        next_rotor = _next;
    else
        next_rotor = nullptr;

    window_ = window_position;
    current_position_ = ALPHABET.find(window_position);
};
void Rotors::Step() {
    if (next_rotor && window_ == turnover_) {
        next_rotor->Step();
    }
    current_position_ = (current_position_ + 1) % 26;
    window_ = ALPHABET[current_position_];
}
std::string Rotors::EncodeDecodeLetter(std::string character) {
    auto character_pos = ALPHABET.find(character);
    auto pos = (character_pos + current_position_) % 26;

    return std::to_string(wiring_[pos]);
}
