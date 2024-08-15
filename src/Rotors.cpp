#include "Rotors.hpp"

#include <cstdio>
#include <iostream>
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
    invert_wiring();
};

void Rotors::invert_wiring() {
    std::string temp_wiring(26, 'A');
    for (int i = 0; i < wiring_.size(); i++) {
        char letter = wiring_[i];
        temp_wiring[letter - 'A'] = 'A' + i;
    }
    inverse_wiring_ = temp_wiring;
}
void Rotors::Step() {
    if (next_rotor && window_ == turnover_) {
        next_rotor->Step();
    }
    current_position_ = (current_position_ + 1) % 26;
    window_ = ALPHABET[current_position_];
    std::cout << " Rotor::Step = " << current_position_
              << " Window = " << window_ << std::endl;
}
const char Rotors::EncodeDecodeLetter(const char& character, bool forwards) {
    int character_pos = ALPHABET.find(character);

    auto pos = (character_pos + current_position_) % 26;
    char output_letter;
    if (forwards) {
        output_letter = wiring_[pos];
    } else {
        output_letter = inverse_wiring_[pos];
    }
    std::cout << "Rotor ::Input =  " << character
              << " output = " << output_letter << " Pos = " << pos << std::endl;
    return output_letter;
}
