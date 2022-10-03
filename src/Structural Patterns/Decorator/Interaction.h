//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_INTERACTION_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_INTERACTION_H

#include <iostream>

namespace StructuralPatterns {
    namespace Decorator {

        class Interaction {
        public:
            Interaction();
            virtual void behaviour();
        };

        class CombinedInteractions : public Interaction {
        public:
            void behaviour() override;
        private:
            void anotherBehaviour();
        };

    } // StructuralPattern
} // Decorator

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_INTERACTION_H
