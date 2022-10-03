//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_BANKACCOUNT_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_BANKACCOUNT_H

#include <string>
#include <memory>

namespace StructuralPatterns {
    namespace Proxy {

        class SecureBankService {
        public:
            explicit SecureBankService(std::string key);
            void getFunds();
        private:
            std::string key;
        };

        class BankAccount {
        public:
            explicit BankAccount(std::string accountName);
            void getFunds();
        private:
            std::string accountName;
            std::unique_ptr<SecureBankService> secureBankService;
        };

    } // StructuralPatterns
} // Proxy

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_BANKACCOUNT_H
