
#include "Reflector.hpp"

Reflector::Reflector(std::string reflector_type)

{
    if (reflector_type == "B") {
        wiring_ = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    } else if (reflector_type == "A") {
        wiring_ = "EJMZALYXVBWFCRQUONTSPIKHGD";
    } else if (reflector_type == "C") {
        wiring_ = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
    }
};

const char Reflector::Encode(int index) { return wiring_[index]; }
