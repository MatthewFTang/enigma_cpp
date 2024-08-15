#include "Enigma.hpp"

#include <iostream>
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
    std::cout << " mesggage size = " << message.size() << std::endl;
    for (int i = 0; i < message.size(); i++) {
        msg += EncodeLetter(message[i]);
    }
    return msg;
}

const char Enigma::EncodeLetter(const char& letter_input) {
    rotor3_.Step();
    std::cout << " input letter " << letter_input << std::endl;
    auto first_out3 = rotor3_.EncodeDecodeLetter(letter_input);
    auto first_out2 = rotor2_.EncodeDecodeLetter(first_out3);
    auto first_out1 = rotor1_.EncodeDecodeLetter(first_out2);
    auto relfector_out = reflector_.Encode(first_out1);
    auto second_out1 = rotor1_.EncodeDecodeLetter(relfector_out, false);
    auto second_out2 = rotor2_.EncodeDecodeLetter(second_out1, false);
    auto second_out3 = rotor3_.EncodeDecodeLetter(second_out2, false);
    return second_out3;
}
