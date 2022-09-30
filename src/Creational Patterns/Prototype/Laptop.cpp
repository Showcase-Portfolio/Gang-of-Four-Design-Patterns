//
// Created by Basam on 1/10/2022.
//

#include "Laptop.h"
#include <iostream>

namespace CreationalPatterns {
    namespace Prototype {
        Laptop::~Laptop() = default;

        std::unique_ptr<Laptop> SmallLaptop::cloneLaptop() {
            return std::unique_ptr<SmallLaptop>(new SmallLaptop());
        }

        void SmallLaptop::turnOn() {
            std::cout << "Small laptop is on" << std::endl;
        }

        std::unique_ptr<Laptop> LargeLaptop::cloneLaptop() {
            return std::unique_ptr<LargeLaptop>(new LargeLaptop());
        }

        void LargeLaptop::turnOn() {
            std::cout << "Large laptop is on" << std::endl;
        }

        std::map<std::string, std::shared_ptr<Laptop>> Factory::laptopPrototypes = std::map<std::string, std::shared_ptr<Laptop>>
                ({
                    {"Small", std::make_shared<SmallLaptop>()},
                    {"Large", std::make_shared<LargeLaptop>()}
                });

        std::shared_ptr<Laptop> Factory::makeLaptop(const std::string& laptopType) {
            return laptopPrototypes[laptopType]->cloneLaptop();
        }
    } // CreationalPatterns
} // Prototype