
// Copyright (c) 2024 Author. All Rights Reserved.
#include "src/Cracker.hpp"

#include <algorithm>
#include <iostream>
#include <ostream>

#include "src/Enigma.hpp"
#include "src/EnigmaSettings.hpp"
float Cracker::IndexOfCoindence(std::string message) {
  float I = 0;

  const double message_length = message.length();
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (auto const &c : alphabet) {
    double count = std::count(message.begin(), message.end(), c);
    I += (count * (count - 1)) / (message_length * (message_length - 1));
  }
  return I;
}
void Cracker::RunOnRings() {
  EnigmaSettings settings;
  Enigma enigma;
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  EnigmaSettings bestsettings;
  double maxFitness = 0;
  settings.plugboard = {};
  for (auto const &ring1 : rings_) {
    settings.rotor_r = ring1;
    for (auto const &ring2 : rings_) {
      settings.rotor_m = ring2;
      for (auto const &ring3 : rings_) {
        settings.rotor_l = ring3;
        std::cout << ring1 << " " << ring2 << " " << ring3 << std::endl;
        for (auto const &i : alphabet) {
          settings.window_setting_r = i;
          for (auto const &j : alphabet) {
            settings.window_setting_m = j;
            for (auto const &k : alphabet) {
              settings.window_setting_l = k;
              enigma.Configure(settings);
              std::string decypt = enigma.Encode(message_);
              float ioc = IndexOfCoindence(decypt);
              if (ioc > maxFitness) {
                maxFitness = ioc;
                bestsettings = settings;
              }
            }
          }
        }
      }
    }
  }
  print_settings_and_message(bestsettings);
}
void Cracker::RunOnPlugboard() {
  // TODO
}
void Cracker::RunOnReflectors() {
  // TODO
}
void Cracker::print_settings_and_message(EnigmaSettings const &settings) {
  std::cout << "Settings " << std::endl;
  std::cout << "Rotor_left = " << settings.rotor_l
            << " Rotor_middle = " << settings.rotor_m
            << " Rotor_right = " << settings.rotor_r << std::endl;
  std::cout << "Ring settings" << std::endl;
  std::cout << "Window left " << settings.window_setting_l << " window middle "
            << settings.window_setting_m << " window right "
            << settings.window_setting_r << std::endl;
  std::cout << "Plugboard settings" << std::endl;
  for (auto it : settings.plugboard)
    std::cout << it.first << "<->" << it.second << std::endl;
}
