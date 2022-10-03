//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_FLYWEIGHT_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_FLYWEIGHT_H

#include <memory>
#include <vector>

namespace StructuralPatterns {
    namespace Flyweight {

        class UserData {
        public:
            explicit UserData(int data);
            unsigned int getData();
        private:
            unsigned int sharedData;
        };

        class FlyweightUserData {
        public:
            static std::shared_ptr<UserData> getUserData(int data);
        private:
            static std::vector<std::shared_ptr<UserData>> userData;
        };

    } // StructuralPatterns
} // Flyweight

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_FLYWEIGHT_H
