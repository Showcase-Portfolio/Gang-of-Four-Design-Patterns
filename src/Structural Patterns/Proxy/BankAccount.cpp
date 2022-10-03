//
// Created by Basam on 3/10/2022.
//

#include "BankAccount.h"
#include <iostream>
#include <utility>

namespace StructuralPatterns {
    namespace Proxy {
        SecureBankService::SecureBankService(std::string key) : key(std::move(key)) {
            std::cout << "Accessing account" << std::endl;
        }

        void SecureBankService::getFunds() {
            if (key == "accountkeyissecureandmatches") {
                std::cout << "Funds in account: $" << 5 << std::endl;
            } else {
                std::cout << "You are not authorised" << std::endl;
            }
        }

        BankAccount::BankAccount(std::string accountName) : secureBankService(nullptr), accountName(accountName) {}

        void BankAccount::getFunds() {
            if(!secureBankService) {
                std::string key = accountName + "keyissecureandmatches";
                secureBankService = std::unique_ptr<SecureBankService>(new SecureBankService(key));
            }

            secureBankService->getFunds();
        }
    } // StructuralPatterns
} // Proxy