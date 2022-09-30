//
// Created by Basam on 1/10/2022.
//

#include "ChessPositions.h"
#include <iostream>

namespace CreationalPatterns {
    namespace Builder {
        ChessPosition::~ChessPosition() = default;

        void ChessPositionA::setupPos() {
            this->posQueen = 7;
            std::cout << this->posKnightOne << " " << this->posQueen << std::endl;
        }

        void ChessPositionB::setupPos() {
            this->posQueen = 42;
            std::cout << this->posKnightOne << " " << this->posQueen << std::endl;
        }

        ChessPositionA::ChessPositionA() {
            this->posKnightOne = 42;
            std::cout << "Chess Position A" << std::endl;
        }

        ChessPositionB::ChessPositionB() {
            this->posKnightOne = 7;
            std::cout << "Chess Position B" << std::endl;
        }

        ChessBoard::ChessBoard(std::unique_ptr<ChessPosition> chessPosition) : chessPosition_(std::move(chessPosition)) {}
    } // CreationalPatterns
} // Builder