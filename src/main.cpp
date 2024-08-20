// Copyright (c) 2024 Author. All Rights Reserved.
#include <fstream>
#include <iostream>

#include "src/Cracker.hpp"
#include "src/Enigma.hpp"
#include "src/EnigmaSettings.hpp"
void printMessage(std::string const &msg);
void print_settings_and_message(EnigmaSettings const &settings,
                                std::string const &msg);
int main() {
  std::string msg;
  std::fstream file;
  file.open("/home/matt/Documents/Github/enigma_cpp/src/text.txt");
  std::string message;
  while (getline(file, msg)) {
    message += msg;
  }

  file.close();
  EnigmaSettings settings;
  settings.plugboard = {};
  settings.rotor_l = "III";
  settings.rotor_m = "II";
  settings.rotor_r = "I";
  settings.window_setting_l = "R";
  settings.window_setting_m = "T";
  settings.window_setting_r = "F";
  Enigma enigma;
  print_settings_and_message(settings, message);
  enigma.Configure(settings);
  auto cipher_text = enigma.Encode(message);
  printMessage(cipher_text);

  Cracker cracker(cipher_text);
  cracker.RunOnRings();
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
