//
// Created by Matthew F Tang on 9/7/2024.
//
#include "IRotor.h"

char IRotor::Encrypt(char letter) {
    int index= (letter  - 'A' +position )%26;
    return wiring[index];
}
