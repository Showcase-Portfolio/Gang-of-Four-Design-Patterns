//
// Created by Basam on 29/09/2022.
//

#include "MedicineManufacturing.h"
#include <iostream>
#include <memory>

namespace CreationalPatterns {
    namespace AbstractFactory {
        Medicine BrandXMedicine::synthesizeMedicine() {
            std::cout << "Brand X Medicine Synthesized" << std::endl;
            return Medicine{};
        }

        Medicine BrandYMedicine::synthesizeMedicine() {
            std::cout << "Brand Y Medicine Synthesized" << std::endl;
            return Medicine{};
        }

        Manufacturer::~Manufacturer() = default;

        std::unique_ptr<BrandXMedicine> Factory::createBrandXMedicine() {
            return std::unique_ptr<BrandXMedicine>(new BrandXMedicine());
        }

        std::unique_ptr<BrandYMedicine> Factory::createBrandYMedicine() {
            return std::unique_ptr<BrandYMedicine>(new BrandYMedicine());
        }
    } // CreationalPatterns
} // AbstractFactory