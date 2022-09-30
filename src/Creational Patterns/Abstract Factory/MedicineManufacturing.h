//
// Created by Basam on 29/09/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_MEDICINEMANUFACTURING_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_MEDICINEMANUFACTURING_H

#include <memory>

namespace CreationalPatterns {
    namespace AbstractFactory {
        class Medicine {};
        class Manufacturer {
        public:
            virtual ~Manufacturer();
            virtual Medicine synthesizeMedicine() = 0;
        };

        class BrandXMedicine : public Manufacturer {
        public:
            Medicine synthesizeMedicine() override;
        };

        class BrandYMedicine : public Manufacturer {
        public:
            Medicine synthesizeMedicine() override;
        };

        class Factory {
        public:
            static std::unique_ptr<BrandXMedicine> createBrandXMedicine();
            static std::unique_ptr<BrandYMedicine> createBrandYMedicine();
        };
    } // CreationalPatterns
} // AbstractFactory

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_MEDICINEMANUFACTURING_H
