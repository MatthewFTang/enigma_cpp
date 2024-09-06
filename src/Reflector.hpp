// Copyright (c) 2024 Author. All Rights Reserved.

#pragma once
#include <string>

class Reflector {
   public:
    Reflector() = default;
    explicit Reflector(std::string const &reflector_type);
    char Encode(int index);

   private:
    std::string wiring_;
};
