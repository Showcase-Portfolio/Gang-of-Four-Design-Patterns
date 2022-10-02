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
#include "Structural Patterns/Bridge/TessaractImplementation.h"
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
            default:
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
    };

    int mappedArg;

    try {
        mappedArg = argMapping.at(arg);
    } catch (const std::out_of_range&) {
        mappedArg = -1;
    }

    return mappedArg;
}
