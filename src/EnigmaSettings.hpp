#pragma once
#include <string>
#include <unordered_map>

struct EnigmaSettings {
    std::string rotor1 = "2";
    std::string rotor2 = "2";
    std::string rotor3 = "2";
    std::string window_1 = "A";
    std::string window_2 = "A";
    std::string window_3 = "A";
    std::string reflector = "B";

    std::unordered_map<std::string, std::string> Plugboard;
};
