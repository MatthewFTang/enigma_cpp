//
// Created by Matthew F Tang on 9/7/2024.
//
#pragma once

#include "IRotor.h"
class Rotor1 : public IRotor {
public:
  //    std::string Encrypt() override;
  //    std::string Decrypt() override;
  //    void rotate() override;
  explicit Rotor1(int _pos) : position(_pos){};

private:
  std::string wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
  int position;
};
