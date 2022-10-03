//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_UNIFIEDINTERFACE_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_UNIFIEDINTERFACE_H

namespace StructuralPatterns {
    namespace Facade {

        class InterfaceA {
        public:
            InterfaceA();
            void action();
        };

        class InterfaceB {
        public:
            InterfaceB();
            void action();
        };

        class InterfaceC {
        public:
            InterfaceC();
            void action();
        };

        class UnifiedInterface {
        public:
            UnifiedInterface();
        private:
            InterfaceA a;
            InterfaceB b;
            InterfaceC c;
        };

    } // StructuralPatterns
} // Facade

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_UNIFIEDINTERFACE_H
