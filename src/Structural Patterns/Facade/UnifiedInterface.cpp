//
// Created by Basam on 3/10/2022.
//

#include "UnifiedInterface.h"
#include <iostream>

namespace StructuralPatterns {
    namespace Facade {
        InterfaceA::InterfaceA() {
            std::cout << "Interface A instantiated" << std::endl;
        }

        void InterfaceA::action() {
            std::cout << "Perform interface A action" << std::endl;
        }

        InterfaceB::InterfaceB() {
            std::cout << "Interface B instantiated" << std::endl;
        }

        void InterfaceB::action() {
            std::cout << "Perform interface B action" << std::endl;
        }

        InterfaceC::InterfaceC() {
            std::cout << "Interface C instantiated" << std::endl;
        }

        void InterfaceC::action() {
            std::cout << "Perform interface C action" << std::endl;
        }

        UnifiedInterface::UnifiedInterface() {
            a.action();
            b.action();
            c.action();
        }
    } // StructuralPatterns
} // Facade