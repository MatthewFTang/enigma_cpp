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
  file.open("/home/matt/Documents/Github/enigma_cpp/src/text2.txt");
  std::string message;
  while (getline(file, msg)) {
    message += msg;
  }

  file.close();
  EnigmaSettings settings;
  settings.plugboard = {};
  settings.rotor_l = "II";
  settings.rotor_m = "V";
  settings.rotor_r = "III";
  settings.reflector = "B";
  settings.window_setting_l = "V";
  settings.window_setting_m = "D";
  settings.window_setting_r = "Z";
  // // Enigma enigma;
  // // print_settings_and_message(settings, message);
  // enigma.Configure(settings);
  // auto cipher_text = enigma.Encode(message);
  // printMessage(cipher_text);

  Cracker cracker(message);
  // cracker.RunOnRings();
  cracker.SetBestSettings(settings);
  cracker.RunOnPlugboard();
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
