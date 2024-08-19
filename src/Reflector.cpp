// Copyright (c) 2024 Author. All Rights Reserved.
#include "Reflector.hpp"

#include <cstring>

Reflector::Reflector(std::string const &reflector_type) {
  if (reflector_type == "B") {
    wiring_ = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
  } else if (reflector_type == "A") {
    wiring_ = "EJMZALYXVBWFCRQUONTSPIKHGD";
  } else if (reflector_type == "C") {
    wiring_ = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
  }
}

const char Reflector::Encode(int index) { return wiring_[index]; }
