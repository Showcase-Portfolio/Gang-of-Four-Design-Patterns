//
// Created by Basam on 3/10/2022.
//

#include "Handler.h"
#include <iostream>
#include <utility>

namespace BehaviouralPatterns {
    namespace ChainOfResponsibility {

        Handler::Handler(unsigned int id) : id(id), next(nullptr) {}

        void Handler::add(const std::shared_ptr<Handler>& Handler) {
            if (next) {
                Handler->set(next);
            }
            next = Handler;
        }

        void Handler::set(std::shared_ptr<Handler> Handler) {
            next = std::move(Handler);
        }

        void Handler::handleRequest(unsigned int id) {
            if (id == this->id) {
                std::cout << id << " successfully handled request" << std::endl;
                return;
            }

            if(next) {
                next->handleRequest(id);
            }
        }

        HandlerOne::HandlerOne(unsigned int id) : Handler(id) {}

        void HandlerOne::handleRequest(unsigned int id) {
            std::cout << "Handler one" << std::endl;
            Handler::handleRequest(id);
        }

        HandlerTwo::HandlerTwo(unsigned int id) : Handler(id) {}

        void HandlerTwo::handleRequest(unsigned int id) {
            std::cout << "Handler two" << std::endl;
            Handler::handleRequest(id);
        }

    } // BehaviouralPatterns
} // Chain of Responsibility