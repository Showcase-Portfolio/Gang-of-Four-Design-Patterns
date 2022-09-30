//
// @author Basam Ahmad
// @Date 29/09/2022
//

#include "main.h"
#include "Creational Patterns/Abstract Factory/MedicineManufacturing.h"
#include <memory>

int main() {
    using namespace CreationalPatterns::AbstractFactory;
    if (true) {
        std::unique_ptr<Manufacturer> m = Factory::createBrandXMedicine();
        auto mOne = m->synthesizeMedicine();
        m = Factory::createBrandYMedicine();
        auto mTwo = m->synthesizeMedicine();
    }
    return 0;
}
