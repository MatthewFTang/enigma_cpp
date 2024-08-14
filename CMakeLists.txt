cmake_minimum_required(VERSION 3.28)
project(Enigma)

set(CMAKE_CXX_STANDARD 23)

add_executable(Enigma main.cpp
        Rotors.h
        IRotor.h
        Rotor1.cpp
        Rotor1.h
        IRotor.cpp)
