#include <iostream>

#include "Enigma.hpp"

void printMessage(std::string msg);

int main() {
    std::string msg = "Test";
    EnigmaSettings settings;
    Enigma enigma;
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
