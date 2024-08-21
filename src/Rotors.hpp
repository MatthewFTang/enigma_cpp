// Copyright (c) 2024 Author. All Rights Reserved.
#pragma once
#include <string>

class Rotors {
 public:
  Rotors() = default;
  Rotors(std::string const& rotor, int ring_setting,
         std::string const& window_setting, Rotors* next = nullptr);
  int EncodeDecodeLetterInt(int index, bool forwards = true);
  void Step();
  const char& returnLetter(int index, bool forwards = true);

 private:
  std::string wiring_;
  std::string inverse_wiring_;
  std::string turnover_;
  std::string window_;
  int current_position_;

  void invert_wiring();
  int pos_modulo(int n, int m);
  std::string I_wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
  std::string II_wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
  std::string III_wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
  std::string IV_wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
  std::string V_wiring = "VZBRGITYUPSDNHLXAWMJQOFECK";

  std::string I_turnover = "Q";
  std::string II_turnover = "E";
  std::string III_turnover = "V";
  std::string IV_turnover = "J";
  std::string V_turnover = "Z";

  Rotors* next_rotor;
};
