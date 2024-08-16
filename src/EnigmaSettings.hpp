#pragma once
#include <string>
#include <unordered_map>

struct EnigmaSettings {
    std::string rotor_l = "3";
    std::string rotor_m = "2";
    std::string rotor_r = "1";
    int ring_setting_l = 0;
    int ring_setting_m = 0;
    int ring_setting_r = 1;
    std::string reflector = "B";

    std::unordered_map<std::string, std::string> Plugboard;
};
