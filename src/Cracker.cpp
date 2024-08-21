
// Copyright (c) 2024 Author. All Rights Reserved.
#include "src/Cracker.hpp"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>

#include "src/Enigma.hpp"
#include "src/EnigmaSettings.hpp"

Cracker::Cracker(std::string const &message) : message_(message) {
  best_settings_.rotor_r = 'A';
  best_settings_.rotor_m = 'A';
  best_settings_.rotor_l = 'A';
  best_settings_.plugboard = {};
  best_settings_.ring_setting_r = 'A';
  best_settings_.ring_setting_m = 'A';
  best_settings_.ring_setting_l = 'A';
}
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
  EnigmaSettings settings = best_settings_;
  Enigma enigma;
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  double maxFitness = 0;
  settings.plugboard = {};  // make sure that no plugs are included
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
                best_settings_ = settings;
              }
            }
          }
        }
      }
    }
  }
  print_settings_and_message(best_settings_);
}
void Cracker::RunOnPlugboard() {
  Enigma enigma;
  enigma.Configure(best_settings_);
  auto original_msg = enigma.Encode(message_);
  float maxFitness = IndexOfCoindence(
      original_msg);  // set the min fitness as the setting with no plugs

  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (auto const &letter_1 : alphabet) {
    double loopMax = 0;
    char best_plug_loop[2];
    auto temp_settings = best_settings_;
    auto original_plugs_for_loop = temp_settings.plugboard;
    for (auto const &letter_2 : alphabet) {
      if (letter_1 >= letter_2) continue;
      auto temp_plugs = original_plugs_for_loop;
      temp_plugs[letter_1] = letter_2;
      temp_settings.plugboard = temp_plugs;
      enigma.Configure(temp_settings);
      auto decrpyt = enigma.Encode(message_);
      auto ioc = IndexOfCoindence(decrpyt);
      if (ioc > loopMax) {
        best_plug_loop[0] = letter_1;
        best_plug_loop[1] = letter_2;
        loopMax = ioc;
      }
    }
    if (loopMax > maxFitness) {
      maxFitness = loopMax;
      best_settings_.plugboard[best_plug_loop[0]] = best_plug_loop[1];
    }
  }
  print_settings_and_message(best_settings_);
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

  Enigma enigma;
  enigma.Configure(settings);
  auto curent_output = enigma.Encode(message_);

  std::cout << "Current message " << std::endl;
  std::cout << curent_output << std::endl;
}
