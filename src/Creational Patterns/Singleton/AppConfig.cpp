//
// Created by Basam on 1/10/2022.
//

#include "AppConfig.h"
#include <iostream>

namespace CreationalPatterns {
    namespace Singleton {
        std::shared_ptr<AppConfig> AppConfig::getAppConfig() {
            if (!appConfig_) {
                std::cout << "No instance exists, creating now..." << std::endl;
                appConfig_ = std::shared_ptr<AppConfig>(new AppConfig());
            } else {
                std::cout << "Sending existing instance" << std::endl;
            }
            return appConfig_;
        }

        std::shared_ptr<AppConfig> AppConfig::appConfig_;

        AppConfig::AppConfig() = default;
    } // CreationalPatterns
} // Singleton