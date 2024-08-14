//
// Created by Matthew F Tang on 9/7/2024.
//

#ifndef ENIGMA_IROTOR_H
#define ENIGMA_IROTOR_H

#include <string>

class IRotor {
public:
    virtual ~IRotor() =default;
     char Encrypt(char letter);
     std::string Decrypt();
     void rotate();
 private:
     std::string wiring;
     int position;
};



#endif//ENIGMA_IROTOR_H
