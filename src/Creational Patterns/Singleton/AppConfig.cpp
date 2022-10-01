//
// Created by Basam on 1/10/2022.
//

#include "AppConfig.h"
#include <iostream>
#include <thread>
#include <mutex>

namespace CreationalPatterns {
    namespace Singleton {
        std::shared_ptr<SingleThreadAppConfig> SingleThreadAppConfig::getAppConfig() {
            if (!appConfig_) {
                std::cout << "No instance exists, creating now..." << std::endl;
                appConfig_ = std::shared_ptr<SingleThreadAppConfig>(new SingleThreadAppConfig());
            } else {
                std::cout << "Sending existing instance" << std::endl;
            }
            return appConfig_;
        }

        std::shared_ptr<SingleThreadAppConfig> SingleThreadAppConfig::appConfig_;

        SingleThreadAppConfig::SingleThreadAppConfig() = default;

        std::mutex m, n;

        std::shared_ptr<MultiThreadAppConfig> MultiThreadAppConfig::singleLockGetAppConfig() {
            std::lock_guard<std::mutex> lock(m);
            if (!appConfig_) {
                std::cout << "No instance exists, creating now..." << std::endl;
                appConfig_ = std::shared_ptr<MultiThreadAppConfig>(new MultiThreadAppConfig());
            } else {
                std::cout << "Sending existing instance" << std::endl;
            }
            return appConfig_;
        }

        std::shared_ptr<MultiThreadAppConfig> MultiThreadAppConfig::doubleLockGetAppConfig() {
            std::lock_guard<std::mutex> lockA(m);
            if (!appConfig_) {
                std::lock_guard<std::mutex> lockB(n);
                if (!appConfig_) {
                    std::cout << "No instance exists, creating now..." << std::endl;
                    appConfig_ = std::shared_ptr<MultiThreadAppConfig>(new MultiThreadAppConfig());
                }
            } else {
                std::cout << "Sending existing instance" << std::endl;
            }
            return appConfig_;
        }


        std::shared_ptr<MultiThreadAppConfig> MultiThreadAppConfig::appConfig_;

        MultiThreadAppConfig::MultiThreadAppConfig() = default;

    } // CreationalPatterns
} // Singleton