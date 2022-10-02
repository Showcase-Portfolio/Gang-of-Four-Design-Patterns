//
// Created by Basam on 2/10/2022.
//

#include "ApiWrapper.h"
#include <iostream>

namespace StructuralPatterns {
    namespace Adapter {
        ApiWrapper::~ApiWrapper() = default;

        LegacyApi::LegacyApi() {
            std::cout << "Legacy Api Called" << std::endl;
        }

        AdapterApi::AdapterApi() : LegacyApi() {}

        void AdapterApi::call() {
            std::cout << "Adapter Api Called" << std::endl;
        }
    } // StructuralPatterns
} // Adapter