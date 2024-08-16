#include "Rotors.hpp"

#include <cstdio>
#include <iostream>
#include <string>

#include "Enigma.hpp"

Rotors::Rotors(std::string rotor, int ring_setting, Rotors* _next) {
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

    // window_ = window_position;
    // auto char_w = window_position.c_str();
    current_position_ = ring_setting;
    invert_wiring();
};

void Rotors::invert_wiring() {
    std::string temp_wiring(26, 'A');
    for (int i = 0; i < 26; i++) {
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
    // std::cout << " Rotor::Step = " << current_position_
    //           << " Window = " << window_ << std::endl;
}
const char Rotors::EncodeDecodeLetter(const char& character, bool forwards) {
    int character_pos = character - 'A';
    auto pos = pos_modulo(character_pos + current_position_, 26);
    char output_letter;
    if (forwards) {
        output_letter = wiring_[pos];
    } else {
        output_letter = inverse_wiring_[pos];
    }
    std::cout << "Rotor ::Input =  " << character
              << " output = " << output_letter << " Pos = " << pos
              << "current_offset " << current_position_ << std::endl;
    return output_letter;
}

int Rotors::EncodeDecodeLetterInt(int index, bool forwards) {
    auto pos = pos_modulo(index + current_position_, 26);
    char output_letter;
    if (forwards) {
        output_letter = wiring_[pos];
    } else {
        output_letter = inverse_wiring_[pos];
    }
    auto output_index = output_letter - 'A';
    output_index = pos_modulo(output_index - current_position_, 26);
    // std::cout << "Rotor :: Output = " << output_index
    //           << " output = " << output_letter << " forwards = " << forwards
    //           << " Pos = " << pos << " current_offset " << current_position_
    //           << std::endl;
    return output_index;
}

const char& Rotors::returnLetter(int index, bool forwards) {
    auto pos = pos_modulo(index + current_position_, 26);
    // if (forwards)
    //     return wiring_[pos];
    // else
    //     return inverse_wiring_[pos];
    return wiring_[index];
}
int Rotors::pos_modulo(int n, int m) {
    int val = n % m;
    if (val < 0) val += m;
    return val;
}
