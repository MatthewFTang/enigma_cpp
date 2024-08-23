// Copyright (c) 2024 Author. All Rights Reserved.

#include <iostream>
#include <iterator>
#include <ostream>
#include <print>
#include <sstream>

#include "Enigma.hpp"
#include "EnigmaSettings.hpp"
void PrintRotorMenu(EnigmaSettings *settings);
void PrintMenu();
void PrintSettings(EnigmaSettings const &settings);

int main(int argc, char *argv[]) {
    EnigmaSettings settings;
    Enigma enigma;
    int option = -1;
    int num_received;

    PrintMenu();

    std::cin >> num_received;

    option = num_received;
    std::cout << "You pressed " << option << std::endl;
    while (option != 5 || option != 6) {
        if (option < 6) {
            switch (option) {
                case 1:
                    PrintRotorMenu(&settings);
                    PrintMenu();
                    break;

                case 2:
                case 3:
                case 4:
                case 5:
                    PrintSettings(settings);
                    PrintMenu();
                    break;

                default:
                    break;
            }
        }
    }
    return 0;
}
void PrintMenu() {
    std::println("1. Set rotors");
    std::println("2. Set window position");
    std::println("3. Set Reflector");
    std::println("4. Enter text");
    std::println("5. Show current settings");
    std::println("6. Encode/Decode with setttings");
    std::println("7. Try to crack encrypted text");
}

void PrintRotorMenu(EnigmaSettings *settings) {
    std::cout << std::endl << std::endl;
    std::println("Set the rotors");
    std::println("Default values -> Left = {} Middle = {} Right = {}",
                 settings->rotor_l, settings->rotor_m, settings->rotor_r);
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string text;
    std::string input_text;
    int count = 0;
    while (ss >> text) {
        input_text += text;
        count++;
    }

    if (count == 3) {
        settings->rotor_l = input_text[0];
        settings->rotor_m = input_text[1];
        settings->rotor_r = input_text[2];
    } else {
        std::println("Wrong number of rotors. You entered {}, enter 3 instead ",
                     count);
    }
}

void PrintSettings(EnigmaSettings const &settings) {
    std::cout << std::endl << std::endl;
    std::cout << "Settings " << std::endl;
    std::cout << "Rotor_left = " << settings.rotor_l
              << " Rotor_middle = " << settings.rotor_m
              << " Rotor_right = " << settings.rotor_r << std::endl;
    std::cout << "Ring settings" << std::endl;
    std::cout << "Window left " << settings.window_setting_l
              << " window middle " << settings.window_setting_m
              << " window right " << settings.window_setting_r << std::endl;
    std::cout << "Plugboard settings" << std::endl;
    for (auto it : settings.plugboard)
        std::cout << it.first << "<->" << it.second << std::endl;
}
