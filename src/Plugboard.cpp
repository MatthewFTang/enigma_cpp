// Copyright (c) 2024 Author. All Rights Reserved.
#include "Plugboard.hpp"

char Plugboard::SwapLetter(char c) {
  auto it = plugboard_settings_.find(c);
  if (it != plugboard_settings_.end()) {
    return it->second;
  }
  auto it_2 = plugboard_settings_reverse_.find(c);
  if (it_2 != plugboard_settings_reverse_.end()) {
    return it_2->second;
  }
  return c;
}
Plugboard::Plugboard(std::unordered_map<char, char> const &mapping)
    : plugboard_settings_(mapping) {
  for (const auto &[first, second] : plugboard_settings_) {
    plugboard_settings_reverse_[second] = first;
  }
}
