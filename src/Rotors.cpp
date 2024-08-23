// Copyright (c) 2024 Author. All Rights Reserved.
#include "Rotors.hpp"

#include <string>

Rotors::Rotors(std::string const& rotor, int ring_setting,
               std::string const& window_setting, Rotors* _next) {
  if (rotor == "I") {
    wiring_ = I_wiring;
    turnover_ = I_turnover;
  } else if (rotor == "II") {
    wiring_ = II_wiring;
    turnover_ = II_turnover;
  } else if (rotor == "III") {
    wiring_ = III_wiring;
    turnover_ = III_turnover;
  } else if (rotor == "IV") {
    wiring_ = IV_wiring;
    turnover_ = IV_turnover;
  } else if (rotor == "V") {
    wiring_ = V_wiring;
    turnover_ = V_turnover;
  }

  if (_next != nullptr)
    next_rotor = _next;
  else
    next_rotor = nullptr;

  window_ = window_setting;
  auto char_w = window_setting.c_str();
  current_position_ = *char_w - 'A';
  invert_wiring();
}

void Rotors::invert_wiring() {
  std::string temp_wiring(26, 'A');
  for (int i = 0; i < 26; i++) {
    char letter = wiring_[i];
    temp_wiring[letter - 'A'] = 'A' + i;
  }
  inverse_wiring_ = temp_wiring;
}
void Rotors::Step() {
  current_position_ = (current_position_ + 1) % 26;
  if (next_rotor != nullptr && window_ == turnover_) {
    next_rotor->Step();
  }
  window_ = current_position_ + 'A';
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
  return output_index;
}

const char& Rotors::returnLetter(int index, bool forwards) {
  return wiring_[index];
}
int Rotors::pos_modulo(int n, int m) {
  int val = n % m;
  if (val < 0) val += m;
  return val;
}
