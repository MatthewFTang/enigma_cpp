#include "Enigma.hpp"

#include <string>

#include "Reflector.hpp"
std::string ALPHABET = "ABCDEFGHIJKLMNOPKRSTQUVWXYZ";

void Enigma::Configure(EnigmaSettings settings) {
    rotor1_ = Rotors(settings.rotor1, settings.window_1);
    rotor2_ = Rotors(settings.rotor2, settings.window_2, &rotor1_);
    rotor3_ = Rotors(settings.rotor3, settings.window_3, &rotor2_);

    reflector_ = Reflector(settings.reflector);
}
void Enigma::Reset() { msg_count_ = 0; };

std::string Enigma::Encode(std::string message) {
    std::string msg = "";
    for (auto const& c : message) {
        msg += EncodeLetter(std::to_string(c));
    }
    return msg;
}

const std::string Enigma::EncodeLetter(std::string letter_input) {
    rotor3_.Step();
    auto first_out3 = rotor3_.EncodeDecodeLetter(letter_input);
    auto first_out2 = rotor2_.EncodeDecodeLetter(first_out3);
    auto first_out1 = rotor1_.EncodeDecodeLetter(first_out2);
    auto relfector_out = reflector_.Encode(first_out1);
    auto second_out1 = rotor1_.EncodeDecodeLetter(relfector_out);
    auto second_out2 = rotor2_.EncodeDecodeLetter(second_out1);
    auto second_out3 = rotor3_.EncodeDecodeLetter(second_out2);
    return second_out3;
}
