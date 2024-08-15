#pragma once
#include <string>
#include <vector>

#include "Rotors.h"
class Enigma {
   public:
    Enigma() = default;
    ~Enigma() = default;

    void Configure(std::string Rotor1, std::string Rotor2, std::string Rotor3,
                   std::string Reflector, std::vector<std::string> Plugboard);
    void Reset();

    std::string Encode(std::string message);
    std::string Decode(std::string cyper_text);

   private:
    Rotors rotor1_;
    Rotors rotor2_;
    Rotors rotor3_;
    int msg_count_ = 0;
};
