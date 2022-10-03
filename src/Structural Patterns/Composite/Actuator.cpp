//
// Created by Basam on 3/10/2022.
//

#include "Actuator.h"
#include <iostream>

namespace StructuralPatterns {
    namespace Composite {

        MachinePart::~MachinePart() = default;

        Actuator::Actuator(double force) : force(force) {}

        void Actuator::move() {
            std::cout << "Actuator moved with " << force << " force" << std::endl;
        }

        void Robot::addComponent(std::unique_ptr<MachinePart> component) {
            robotPart.push_back(std::move(component));
        }

        void Robot::move() {
            robotParts selectedPart = robotPart.begin();
            robotParts lastPart = robotPart.end();
            for(; selectedPart != lastPart; ++selectedPart) {
                (*selectedPart)->move();
            }
        }
    } // StructuralPatterns
} // Composite