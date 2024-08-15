

#pragma once
#include <string>
#include <unordered_map>
class Reflector {
   public:
    Reflector() = default;
    Reflector(std::string reflector_type);
    const char Encode(const char input);

   private:
    std::unordered_map<char, char> wiring_;
};
