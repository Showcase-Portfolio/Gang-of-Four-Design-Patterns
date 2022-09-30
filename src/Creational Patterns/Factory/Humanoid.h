//
// Created by Basam on 1/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_HUMANOID_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_HUMANOID_H

namespace CreationalPatterns {
    namespace Factory {

        class Humanoid {
        public:
            virtual ~Humanoid();
            virtual void run() = 0;
        };

        class Dwarf : public Humanoid {
        public:
            Dwarf();
            void run() override;
        };

        class Elf : public Humanoid {
        public:
            Elf();
            void run() override;
        };

    } // CreationalPatterns
} // Builder

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_HUMANOID_H
