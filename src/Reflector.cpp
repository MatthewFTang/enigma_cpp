
#include "Reflector.hpp"

Reflector::Reflector(std::string reflector_type)

{
    if (reflector_type == "B") {
        wiring_ = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    }
};

const char Reflector::Encode(int index) { return wiring_[index]; }
