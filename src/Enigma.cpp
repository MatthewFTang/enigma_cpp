// Copyright (c) 2024 Author. All Rights Reserved.
#include "Enigma.hpp"

void Enigma::Configure(EnigmaSettings const& settings) {
  rotor_l_ = Rotors(settings.rotor_l, settings.ring_setting_l,
                    settings.window_setting_l);

  rotor_m_ = Rotors(settings.rotor_m, settings.ring_setting_m,
                    settings.window_setting_m, &rotor_l_);
  rotor_r_ = Rotors(settings.rotor_r, settings.ring_setting_r,
                    settings.window_setting_r, &rotor_m_);
  reflector_ = Reflector(settings.reflector);
  plugboard_ = Plugboard(settings.plugboard);
}

std::string Enigma::Encode(std::string const& message) {
  std::string msg = "";
  for (const auto& c : message) {
    msg += EncodeLetter(c);
  }
  return msg;
}

char Enigma::EncodeLetter(const char letter_input) {
  auto new_letter_input = plugboard_.SwapLetter(letter_input);
  rotor_r_.Step();
  int firstIndex = new_letter_input - 'A';

  auto first_out3 = rotor_r_.EncodeDecodeLetterInt(firstIndex);
  auto first_out2 = rotor_m_.EncodeDecodeLetterInt(first_out3);
  auto first_out1 = rotor_l_.EncodeDecodeLetterInt(first_out2);

  auto relfector_out = reflector_.Encode(first_out1);

  auto second_out1 = rotor_l_.EncodeDecodeLetterInt(relfector_out - 'A', false);
  auto second_out2 = rotor_m_.EncodeDecodeLetterInt(second_out1, false);
  auto second_out3 = rotor_r_.EncodeDecodeLetterInt(second_out2, false);
  auto output_letter = second_out3 + 'A';
  output_letter = plugboard_.SwapLetter(output_letter);

  return output_letter;
}
