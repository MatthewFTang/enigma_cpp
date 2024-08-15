#pragma once
#include <string>

#include "EnigmaSettings.hpp"
#include "Reflector.hpp"
#include "Rotors.hpp"
extern std::string ALPHABET;
class Enigma {
   public:
    Enigma() = default;
    ~Enigma() = default;

    void Configure(EnigmaSettings settings);
    void Reset();

    std::string Encode(std::string message);

   private:
    const std::string EncodeLetter(std::string letter_input);
    Rotors rotor1_;
    Rotors rotor2_;
    Rotors rotor3_;
    Reflector reflector_;
    int msg_count_ = 0;
};
