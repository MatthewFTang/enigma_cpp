cmake_minimum_required(VERSION 3.28)
project(Enigma)

set(CMAKE_CXX_STANDARD 23)

add_executable(Enigma src/main.cpp
        src/Rotors.h
        src/Rotors.cpp
        src/Reflector.hpp
        src/Reflector.cpp
        src/EnigmaSettings.hpp
        src/Enigma.hpp
        src/Enigma.cpp
)
