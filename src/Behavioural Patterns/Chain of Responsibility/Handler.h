//
// Created by Basam on 3/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_Handler_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_Handler_H

#include<memory>

namespace BehaviouralPatterns {
    namespace ChainOfResponsibility {
        class Handler {
        public:
            explicit Handler(unsigned int id);
            void add(const std::shared_ptr<Handler>& container);
            void set(std::shared_ptr<Handler> container);
            virtual void handleRequest(unsigned int id);
        protected:
            unsigned int id;
        private:
            std::shared_ptr<Handler> next;
        };

        class HandlerOne : public Handler {
        public:
            explicit HandlerOne(unsigned int id);
            void handleRequest(unsigned int id) override;
        };

        class HandlerTwo : public Handler {
        public:
            HandlerTwo(unsigned int id);
            void handleRequest(unsigned int id) override;
        };

    } // BehaviouralPatterns
} // Chain of Responsibility

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_Handler_H
