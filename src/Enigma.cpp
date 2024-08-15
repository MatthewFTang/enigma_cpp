#include "Enigma.hpp"

#include "Rotors.h"
void Enigma::Configure(std::string Rotor1, std::string Rotor2,
                       std::string Rotor3, std::string Reflector,
                       std::vector<std::string> Plugboard) {
    Rotors rotor1 = Rotors(Rotor1);
    Rotors rotor2 = Rotors(Rotor2);
    Rotors rotor3 = Rotors(Rotor3);
}
void Enigma::Reset() { msg_count_ = 0; };

std::string Enigma::Encode(std::string message) { return "none"; }
std::string Enigma::Decode(std::string cyper_text) { return "none"; };
