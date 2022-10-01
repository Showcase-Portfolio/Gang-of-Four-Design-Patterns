//
// Created by Basam on 1/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H

#include<memory>

namespace CreationalPatterns {
    namespace Singleton {

        class SingleThreadAppConfig {
        public:
            static std::shared_ptr<SingleThreadAppConfig> getAppConfig();
        private:
            SingleThreadAppConfig();
            static std::shared_ptr<SingleThreadAppConfig> appConfig_;
        };

        class MultiThreadAppConfig {
        public:
            static std::shared_ptr<MultiThreadAppConfig> singleLockGetAppConfig();
            static std::shared_ptr<MultiThreadAppConfig> doubleLockGetAppConfig();

        private:
            MultiThreadAppConfig();
            static std::shared_ptr<MultiThreadAppConfig> appConfig_;
        };

    } // CreationalPatterns
} // Singleton

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H
