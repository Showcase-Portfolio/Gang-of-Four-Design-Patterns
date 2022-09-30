//
// Created by Basam on 1/10/2022.
//

#include "Humanoid.h"
#include <iostream>

namespace CreationalPatterns {
    namespace Factory {
        Humanoid::~Humanoid() = default;

        Dwarf::Dwarf() {
            std::cout << "Dwarf created" << std::endl;
        }

        void Dwarf::run() {
            std::cout << "Dwarf running slowly..." << std::endl;
        }

        Elf::Elf() {
            std::cout << "Elf created" << std::endl;
        }

        void Elf::run() {
            std::cout << "Elf Running elegantly..." << std::endl;
        }
    } // CreationalPatterns
} // Builder