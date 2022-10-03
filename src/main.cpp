//
// @author Basam Ahmad
// @Date 29/09/2022
//

#include "main.h"
#include "Creational Patterns/Abstract Factory/MedicineManufacturing.h"
#include "Creational Patterns/Builder/ChessPositions.h"
#include "Creational Patterns/Factory/Humanoid.h"
#include "Creational Patterns/Prototype/Laptop.h"
#include "Creational Patterns/Singleton/AppConfig.h"
#include "Structural Patterns/Adapter/ApiWrapper.h"
#include "Structural Patterns/Bridge/HyperCube.h"
#include "Structural Patterns/Composite/Actuator.h"
#include "Structural Patterns/Decorator/Interaction.h"
#include "Structural Patterns/Facade/UnifiedInterface.h"
#include "Structural Patterns/Flyweight/UserData.h"
#include "Structural Patterns/Proxy/BankAccount.h"
#include "Behavioural Patterns/Chain of Responsibility/Handler.h"
#include <memory>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1) {
        switch(parseArguments(argv[1])) {
            case AbstractFactory: {
                using namespace CreationalPatterns::AbstractFactory;
                std::unique_ptr<Manufacturer> m = Factory::createBrandXMedicine();
                auto mOne = m->synthesizeMedicine();
                m = Factory::createBrandYMedicine();
                auto mTwo = m->synthesizeMedicine();
                break;
            }
            case Builder: {
                using namespace CreationalPatterns::Builder;
                std::unique_ptr<ChessPosition> chessPosition(new ChessPositionA());
                chessPosition->setupPos();
                ChessBoard chessBoardOne (ChessBoard(std::move(chessPosition)));
                chessPosition = std::unique_ptr<ChessPositionB>(new ChessPositionB);
                chessPosition->setupPos();
                ChessBoard chessBoardTwo (ChessBoard(std::move(chessPosition)));
                break;
            }
            case Factory: {
                using namespace CreationalPatterns::Factory;
                std::unique_ptr<Humanoid> humanoid(new Elf());
                humanoid->run();
                humanoid = std::unique_ptr<Dwarf>(new Dwarf());
                humanoid->run();
                break;
            }
            case Prototype: {
                using namespace CreationalPatterns::Prototype;
                std::shared_ptr<Laptop> laptop(Factory::makeLaptop("Small"));
                laptop->turnOn();
                laptop = Factory::makeLaptop("Large");
                laptop->turnOn();
                break;
            }
            case Singleton: {
                using namespace CreationalPatterns::Singleton;
                std::shared_ptr<SingleThreadAppConfig> appConfig = SingleThreadAppConfig::getAppConfig();
                appConfig->getAppConfig();

                std::shared_ptr<MultiThreadAppConfig> multiTAppConfig = MultiThreadAppConfig::singleLockGetAppConfig();
                multiTAppConfig->singleLockGetAppConfig();
                multiTAppConfig = MultiThreadAppConfig::doubleLockGetAppConfig();
                multiTAppConfig->doubleLockGetAppConfig();
                break;
            }
            case Adapter: {
                using namespace StructuralPatterns::Adapter;
                auto adapterApi = AdapterApi();
                adapterApi.call();
            }
            case Bridge: {
                using namespace StructuralPatterns::Bridge;
                Square square;
                Tesseract tesseract;
            }
            case Composite: {
                using namespace StructuralPatterns::Composite;
                std::unique_ptr<Actuator> aOne(new Actuator(42.3));
                std::unique_ptr<Actuator> aTwo(new Actuator(77.7));
                Robot r;
                r.addComponent(std::move(aOne));
                r.addComponent(std::move(aTwo));
                r.move();
            }
            case Decorator: {
                using namespace StructuralPatterns::Decorator;
                CombinedInteractions interactions;
                interactions.behaviour();
            }
            case Facade: {
                using namespace StructuralPatterns::Facade;
                UnifiedInterface unifiedInterface;
            }
            case Flyweight: {
                using namespace StructuralPatterns::Flyweight;
                std::unique_ptr<FlyweightUserData> userData(new FlyweightUserData);
                userData->getUserData(3);
                userData->getUserData(3);
            }
            case Proxy: {
                using namespace StructuralPatterns::Proxy;
                BankAccount validAccount("account");
                BankAccount invalidAccount("acc0unt");
                validAccount.getFunds();
                invalidAccount.getFunds();
            }
            case ChainOfResponsibility: {
                using namespace BehaviouralPatterns::ChainOfResponsibility;
                auto hTwo = std::make_shared<HandlerTwo>(7);
                auto hOne = std::make_shared<HandlerOne>(33);
                Handler h(0);

                h.add(hTwo);
                h.add(hOne);
                h.handleRequest(7);
                h.handleRequest(33);
            }
            default:
                std::cout << "Invalid argument: " << argv[1] << std::endl;
                break;
        }
    }
    return 0;
}

int parseArguments(const std::string& arg) {
    const std::map<std::string, int> argMapping {
            {"AbstractFactory", AbstractFactory},
            {"Builder", Builder},
            {"Factory", Factory},
            {"Prototype", Prototype},
            {"Singleton", Singleton},
            {"Adapter", Adapter},
            {"Bridge", Bridge},
            {"Composite", Composite},
            {"Decorator", Decorator},
            {"Facade", Facade},
            {"Flyweight", Flyweight},
            {"Proxy", Proxy},
            {"ChainOfResponsibility", ChainOfResponsibility}
    };

    int mappedArg;

    try {
        mappedArg = argMapping.at(arg);
    } catch (const std::out_of_range&) {
        mappedArg = -1;
    }

    return mappedArg;
}
