//
// Created by Matthew F Tang on 9/7/2024.
//

#pragma once
#include <string>

class IRotor {
public:
  virtual ~IRotor() = default;
  char Encrypt(char letter);
  std::string Decrypt();
  void rotate();

private:
  std::string wiring;
  int position;
};
