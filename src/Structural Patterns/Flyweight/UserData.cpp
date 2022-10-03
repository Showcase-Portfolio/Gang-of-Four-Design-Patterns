//
// Created by Basam on 3/10/2022.
//

#include "UserData.h"
#include <iostream>

namespace StructuralPatterns {
    namespace Flyweight {
        UserData::UserData(int data) : sharedData(data) {}

        unsigned int UserData::getData() {
            return sharedData;
        }

        std::shared_ptr<UserData> FlyweightUserData::getUserData(int data) {
            for (auto current = userData.begin(); current != userData.end(); ++current) {
                if ((*current)->getData() == data) {
                    std::cout << "Reusing user metadata: " << data << std::endl;
                    return *current;
                }
            }

            userData.push_back(std::unique_ptr<UserData>(new UserData(data)));

            std::cout << "Created new user data: " << data << std::endl;

            return userData.back();
        }

        std::vector<std::shared_ptr<UserData>> FlyweightUserData::userData;
    } // StructuralPatterns
} // Flyweight