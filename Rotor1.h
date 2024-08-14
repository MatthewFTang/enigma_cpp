//
// Created by Matthew F Tang on 9/7/2024.
//

#ifndef ENIGMA_ROTOR1_H
#define ENIGMA_ROTOR1_H

#include "IRotor.h"
class Rotor1 :public IRotor{
public:

//    std::string Encrypt() override;
//    std::string Decrypt() override;
//    void rotate() override;
    explicit Rotor1(int _pos):position(_pos){};
private:
    std::string wiring ="EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    int position;
};


#endif//ENIGMA_ROTOR1_H
