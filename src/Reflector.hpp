

#pragma once
#include <string>
class Reflector {
   public:
    Reflector() = default;
    Reflector(std::string reflector_type);
    const char Encode(int index);

   private:
    std::string wiring_;
};
