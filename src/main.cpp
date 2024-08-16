#include <cstdio>
#include <iostream>

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"

void printMessage(std::string msg);
void print_settings_and_message(EnigmaSettings settings, std::string msg);
int main() {
    std::string msg = "AAAAAAA";

    EnigmaSettings settings;

    Enigma enigma;
    print_settings_and_message(settings, msg);
    enigma.Configure(settings);
    auto cipher_text = enigma.Encode(msg);
    printMessage(cipher_text);
    return 0;
}

void printMessage(std::string msg) {
    for (auto const &c : msg) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

void print_settings_and_message(EnigmaSettings settings, std::string msg) {
    std::cout << "Settings " << std::endl;
    std::cout << "Rotor_left = " << settings.rotor_l
              << " Rotor_middle = " << settings.rotor_m
              << " Rotor_right = " << settings.rotor_r << std::endl;
    std::cout << "Message to send : " << msg << std::endl;
}
