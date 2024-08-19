// Copyright 2024 Matthew Tang
#pragma once
#include <unordered_map>
class Plugboard {
 public:
  Plugboard() = default;
  explicit Plugboard(std::unordered_map<char, char> const &mapping);
  char SwapLetter(char c);

 private:
  std::unordered_map<char, char> plugboard_settings_;
  std::unordered_map<char, char> plugboard_settings_reverse_;
};
