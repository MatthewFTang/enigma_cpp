// Copyright (c) 2024 Author. All Rights Reserved.
#include <iostream>

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"

void printMessage(std::string const &msg);
void print_settings_and_message(EnigmaSettings const &settings,
                                std::string const &msg);
int main() {
  std::string msg =
      "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAA";

  EnigmaSettings settings;

  Enigma enigma;
  print_settings_and_message(settings, msg);
  enigma.Configure(settings);
  auto cipher_text = enigma.Encode(msg);
  printMessage(cipher_text);
  return 0;
}

void printMessage(std::string const &msg) {
  int count = 1;
  for (auto const &c : msg) {
    std::cout << c << "";
    if (count % 5 == 0) {
      std::cout << " ";
    }
    count++;
  }
  std::cout << std::endl;
}

void print_settings_and_message(EnigmaSettings const &settings,
                                std::string const &msg) {
  std::cout << "Settings " << std::endl;
  std::cout << "Rotor_left = " << settings.rotor_l
            << " Rotor_middle = " << settings.rotor_m
            << " Rotor_right = " << settings.rotor_r << std::endl;
  std::cout << "Plugboard settings" << std::endl;
  for (auto it : settings.plugboard)
    std::cout << it.first << "<->" << it.second << std::endl;
  std::cout << "Message to send : " << msg << std::endl;
}
