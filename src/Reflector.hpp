

#pragma once
#include <string>
#include <unordered_map>
class Reflector {
   public:
    Reflector() = default;
    Reflector(std::string reflector_type);
    std::string Encode(std::string input);

   private:
    std::unordered_map<std::string, std::string> wiring_;
};
