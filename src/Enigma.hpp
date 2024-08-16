#pragma once
#include <string>

#include "EnigmaSettings.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotors.hpp"
extern std::string ALPHABET;
class Enigma {
   public:
    Enigma() = default;
    ~Enigma() = default;

    void Configure(EnigmaSettings settings);

    std::string Encode(std::string message);

   private:
    char EncodeLetter(const char input_letter);
    Rotors rotor_r_;
    Rotors rotor_m_;
    Rotors rotor_l_;
    Reflector reflector_;
    Plugboard plugboard_;
};
