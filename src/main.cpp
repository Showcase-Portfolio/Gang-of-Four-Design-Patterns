//
// @author Basam Ahmad
// @Date 29/09/2022
//

#include "main.h"
#include "Creational Patterns/Abstract Factory/MedicineManufacturing.h"
#include "Creational Patterns/Builder Design Pattern/ChessPositions.h"
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
                std::unique_ptr<ChessPosition> chessPosition(std::unique_ptr<ChessPositionA>(new ChessPositionA()));
                chessPosition->setupPos();
                ChessBoard chessBoardOne (ChessBoard(std::move(chessPosition)));
                chessPosition = std::unique_ptr<ChessPositionB>(new ChessPositionB);
                chessPosition->setupPos();
                ChessBoard chessBoardTwo (ChessBoard(std::move(chessPosition)));
            }
            default:
                break;
        };
    }
    return 0;
}

int parseArguments(const std::string& arg) {
    const std::map<std::string, int> argMapping {
            {"AbstractFactory", AbstractFactory},
            {"Builder", Builder}
    };

    int mappedArg;

    try {
        mappedArg = argMapping.at(arg);
    } catch (const std::out_of_range&) {
        mappedArg = -1;
    }

    return mappedArg;
}
