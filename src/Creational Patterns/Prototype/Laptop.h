//
// Created by Basam on 1/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_LAPTOP_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_LAPTOP_H

#include <memory>
#include <string>
#include <map>

namespace CreationalPatterns {
    namespace Prototype {

        class Laptop {
        public:
            virtual ~Laptop();
            virtual std::unique_ptr<Laptop> cloneLaptop() = 0;
            virtual void turnOn() = 0;
        };

        class Factory {
        public:
            static std::shared_ptr<Laptop> makeLaptop(const std::string& laptopType);
        private:
            static std::map<std::string, std::shared_ptr<Laptop>> laptopPrototypes;
        };

        class SmallLaptop : public Laptop {
        public:
            std::unique_ptr<Laptop> cloneLaptop() override;
            void turnOn() override;
        };

        class LargeLaptop : public Laptop {
        public:
            std::unique_ptr<Laptop> cloneLaptop() override;
            void turnOn() override;
        };

    } // CreationalPatterns
} // Prototype

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_LAPTOP_H
