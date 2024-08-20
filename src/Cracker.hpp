// Copyright (c) 2024 Author. All Rights Reserved.
#pragma once
#include <string>
#include <vector>

#include "src/EnigmaSettings.hpp"

class Cracker {
 public:
  Cracker() = default;
  explicit Cracker(std::string const &message) : message_(message) {}

  void RunOnRings();
  void RunOnPlugboard();
  void RunOnReflectors();
  float IndexOfCoindence(std::string);

 private:
  std::string message_;
  std::vector<std::string> rings_{"I", "II", "III"};
  int ring_settings_ = 26;
  void print_settings_and_message(EnigmaSettings const &settings);
};
