//
// Created by Basam on 1/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H

#include<memory>

namespace CreationalPatterns {
    namespace Singleton {

        class AppConfig {
        public:
            static std::shared_ptr<AppConfig> getAppConfig();
        private:
            AppConfig();
            static std::shared_ptr<AppConfig> appConfig_;
        };

    } // CreationalPatterns
} // Singleton

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_APPCONFIG_H
