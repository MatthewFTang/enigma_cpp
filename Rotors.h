//
// Created by Matthew F Tang on 9/7/2024.
//

#ifndef ENIGMA_ROTORS_H
#define ENIGMA_ROTORS_H

#include <string>

class Rotors {

    std::string I_wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    std::string II_wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    std::string III_wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    std::string IV_wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";

    std::string I_turnover = "Q";
    std::string II_turnover ="E";
    std::string III_turnover = "V";
    std::string IV_turnover = "J";

};


#endif//ENIGMA_ROTORS_H
