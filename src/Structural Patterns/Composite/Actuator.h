//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_ACTUATOR_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_ACTUATOR_H

#include <vector>
#include <memory>

namespace StructuralPatterns {
    namespace Composite {

        class MachinePart {
        public:
            virtual ~MachinePart();
            virtual void move() = 0;
        };

        class Actuator : public MachinePart {
        public:
            explicit Actuator(double force);
            void move() override;
        private:
            double force;
        };

        class Robot : public MachinePart {
        private:
            std::vector<std::unique_ptr<MachinePart>> robotPart;
            typedef std::vector<std::unique_ptr<MachinePart>>::const_iterator robotParts;
        public:
            void addComponent(std::unique_ptr<MachinePart> component);
            void move() override;
        };

    } // StructuralPatterns
} // Composite

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_ACTUATOR_H
