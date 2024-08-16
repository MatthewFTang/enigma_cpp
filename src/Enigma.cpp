#include "Enigma.hpp"

#include <string>

#include "Reflector.hpp"
std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Enigma::Configure(EnigmaSettings settings) {
    rotor_r_ = Rotors(settings.rotor_r, settings.ring_setting_r);
    rotor_m_ = Rotors(settings.rotor_m, settings.ring_setting_m, &rotor_r_);
    rotor_l_ = Rotors(settings.rotor_l, settings.ring_setting_l, &rotor_m_);

    reflector_ = Reflector(settings.reflector);
}
void Enigma::Reset() { msg_count_ = 0; };

std::string Enigma::Encode(std::string message) {
    std::string msg = "";
    // std::cout << std::endl
    //           << " mesggage size = " << message.size() << std::endl;
    for (const auto& c : message) {
        msg += EncodeLetter(c);
    }
    return msg;
}

const char Enigma::EncodeLetter(const char& letter_input) {
    rotor_r_.Step();
    // std::cout << " input letter " << letter_input << std::endl;
    int firstIndex = letter_input - 'A';

    auto first_out3 = rotor_r_.EncodeDecodeLetterInt(firstIndex);
    auto first_out2 = rotor_m_.EncodeDecodeLetterInt(first_out3);
    auto first_out1 = rotor_l_.EncodeDecodeLetterInt(first_out2);

    auto relfector_out = reflector_.Encode(first_out1);

    // std::cout << "first out " << first_out1 << " out encoder " <<
    // relfector_out
    // << std::endl;
    auto second_out1 =
        rotor_l_.EncodeDecodeLetterInt(relfector_out - 'A', false);
    auto second_out2 = rotor_m_.EncodeDecodeLetterInt(second_out1, false);
    auto second_out3 = rotor_r_.EncodeDecodeLetterInt(second_out2, false);
    auto output_letter = ALPHABET[second_out3];
    return output_letter;
}
