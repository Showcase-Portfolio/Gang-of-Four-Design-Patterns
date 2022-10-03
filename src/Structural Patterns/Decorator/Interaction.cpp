//
// Created by Basam on 3/10/2022.
//

#include "Interaction.h"

namespace StructuralPatterns {
    namespace Decorator {

        Interaction::Interaction() {
            std::cout << "Interaction defined" << std::endl;
        }

        void Interaction::behaviour() {
            std::cout << "Performing default behaviour" << std::endl;
        }

        void CombinedInteractions::behaviour() {
            Interaction::behaviour();
            anotherBehaviour();
        }

        void CombinedInteractions::anotherBehaviour() {
            std::cout << "Performing additional behaviour" << std::endl;
        }
    } // StructuralPattern
} // Decorator