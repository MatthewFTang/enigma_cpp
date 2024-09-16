// Copyright (c) 2024 Author. All Rights Reserved.
#pragma once
#include <string>

class Rotors {
   public:
    Rotors() = default;
    Rotors(std::string const& rotor, int ring_setting,
           std::string const& window_setting, Rotors* next = nullptr);
    ~Rotors() = default;
    int EncodeDecodeLetterInt(int index, bool forwards = true);
    void Step();
    const char& returnLetter(int index, bool forwards = true);

   private:
    std::string wiring_;
    std::string inverse_wiring_;
    std::string turnover_;
    std::string window_;
    int current_position_{};

    void invert_wiring();
    static int pos_modulo(int n, int m) {
        int val = n % m;
        if (val < 0) val += m;
        return val;
    }

    std::string I_wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    std::string II_wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    std::string III_wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    std::string IV_wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    std::string V_wiring = "VZBRGITYUPSDNHLXAWMJQOFECK";
    std::string VI_wiring = "JPGVOUMFYQBENHZRDKASXLICTW";
    std::string VII_wiring = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
    std::string VIII_wiring = "FKQHTLXOCBJSPDZRAMEWNIUYGVDT";

    std::string I_turnover = "Q";
    std::string II_turnover = "E";
    std::string III_turnover = "V";
    std::string IV_turnover = "J";
    std::string V_turnover = "Z";
    std::string VI_turnover = "Z";
    std::string VII_turnover = "Z";
    std::string VIII_turnover = "Z";
    Rotors* next_rotor{};
};
