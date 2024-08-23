// Copyright (c) 2024 Author. All Rights Reserved.
#pragma once
#include <string>
#include <unordered_set>
#include <vector>

#include "EnigmaSettings.hpp"

class Cracker {
 public:
  Cracker() = delete;
  explicit Cracker(std::string const &message);

  void RunOnRings();
  void RunOnPlugboard();
  void RunOnReflectors();
  EnigmaSettings GetCurrentSettings() { return best_settings_; }
  void SetBestSettings(EnigmaSettings const &settings) {
    best_settings_ = settings;
  }

 private:
  float IndexOfCoindence(std::string);
  EnigmaSettings findPlug(std::string unpluggedCharacters, float currentFitness,
                          EnigmaSettings current_setting);
  std::string findUnpluggedLetters(std::unordered_map<char, char> plugboard);
  std::string const &message_;
  std::vector<std::string> rings_{"I", "II", "III", "IV", "V"};
  int ring_settings_ = 26;
  int maxPlugs_ = 10;
  EnigmaSettings best_settings_;
  void print_settings_and_message(EnigmaSettings const &settings);
};
