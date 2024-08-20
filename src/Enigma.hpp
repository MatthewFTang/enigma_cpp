// copyright 2024 Matthew Tang
//
#pragma once
#include <string>

#include "src/EnigmaSettings.hpp"
#include "src/Plugboard.hpp"
#include "src/Reflector.hpp"
#include "src/Rotors.hpp"
class Enigma {
 public:
  Enigma() = default;
  ~Enigma() = default;

  void Configure(EnigmaSettings const &settings);
  void Reset();

  std::string Encode(std::string const &message);

 private:
  char EncodeLetter(const char input_letter);
  std::string ParseMessage(std::string message);
  Rotors rotor_r_;
  Rotors rotor_m_;
  Rotors rotor_l_;
  Reflector reflector_;
  Plugboard plugboard_;
};
