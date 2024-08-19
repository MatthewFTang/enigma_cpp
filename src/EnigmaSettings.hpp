// Copyright 2024 Matthew Tang

#pragma once
#include <string>
#include <unordered_map>

struct EnigmaSettings {
    std::string rotor_l = "III";
    std::string rotor_m = "II";
    std::string rotor_r = "I";
    std::string window_setting_l = "A";
    std::string window_setting_m = "A";
    std::string window_setting_r = "A";
    int ring_setting_l = 0;
    int ring_setting_m = 0;
    int ring_setting_r = 0;
    std::string reflector = "B";
    std::unordered_map<char, char> plugboard = {
        {'A', 'Y'}, {'B', 'E'}, {'H', 'I'}};
};
