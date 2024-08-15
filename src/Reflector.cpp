

#include "Reflector.hpp"
Reflector::Reflector(std::string reflector_type) {
    if (reflector_type == "B") {
        wiring_["A"] = "Y";
        wiring_["B"] = "R";
        wiring_["C"] = "U";
        wiring_["D"] = "H";
        wiring_["E"] = "Q";
        wiring_["F"] = "S";
        wiring_["G"] = "L";
        wiring_["H"] = "D";
        wiring_["I"] = "P";
        wiring_["J"] = "X";
        wiring_["K"] = "N";
        wiring_["L"] = "G";
        wiring_["M"] = "O";
        wiring_["N"] = "K";
        wiring_["O"] = "M";
        wiring_["P"] = "I";
        wiring_["Q"] = "Q";
        wiring_["R"] = "B";
        wiring_["S"] = "F";
        wiring_["T"] = "Z";
        wiring_["U"] = "C";
        wiring_["V"] = "W";
        wiring_["W"] = "V";
        wiring_["X"] = "J";
        wiring_["Y"] = "A";
        wiring_["Z"] = "T";
    } else if (reflector_type == "C") {
        wiring_["A"] = "Y";
        wiring_["B"] = "R";
        wiring_["C"] = "U";
        wiring_["D"] = "H";
        wiring_["E"] = "Q";
        wiring_["F"] = "S";
        wiring_["G"] = "L";
        wiring_["A"] = "Y";
        wiring_["I"] = "P";
        wiring_["J"] = "X";
        wiring_["K"] = "N";
        wiring_["L"] = "Y";
        wiring_["M"] = "Y";
        wiring_["N"] = "O";
        wiring_["O"] = "Z";
        wiring_["P"] = "O";
        wiring_["Q"] = "O";
        wiring_["R"] = "O";
        wiring_["S"] = "O";
        wiring_["T"] = "O";
        wiring_["U"] = "O";
        wiring_["V"] = "W";
        wiring_["W"] = "Z";
        wiring_["X"] = "Z";
        wiring_["Y"] = "Z";
        wiring_["Z"] = "Z";
    }
}
std::string Reflector::Encode(std::string input) { return wiring_[input]; }
