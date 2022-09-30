//
// Created by Basam on 1/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_CHESSPOSITIONS_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_CHESSPOSITIONS_H

#include <memory>

namespace CreationalPatterns {
    namespace Builder {
        class ChessPosition {
        public:
            virtual ~ChessPosition();
            virtual void setupPos() = 0;
        protected:
            int posKnightOne;
            int posKnightTwo;
            int posQueen;
            int posOfPiece;
        };

        class ChessPositionA : public ChessPosition {
        public:
            ChessPositionA();
            void setupPos() override;
        };

        class ChessPositionB : public ChessPosition {
        public:
            ChessPositionB();
            void setupPos() override;
        };

        class ChessBoard {
        public:
            explicit ChessBoard(std::unique_ptr<ChessPosition> chessPosition);
        private:
            std::unique_ptr<ChessPosition> chessPosition_;
        };
    } // CreationalPatterns
} // Builder

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_CHESSPOSITIONS_H
