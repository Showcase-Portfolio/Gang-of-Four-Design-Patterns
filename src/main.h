//
// Created by Basam on 29/09/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_MAIN_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_MAIN_H

#include <map>
#include <stdexcept>

enum mapping {
    AbstractFactory,
    Builder,
    Factory,
    Prototype,
    Singleton,
    Adapter,
    Bridge,
    Composite,
    Decorator,
    Facade,
    Flyweight,
    Proxy,
    ChainOfResponsibility,
};

int parseArguments(const std::string& arg);

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_MAIN_H
