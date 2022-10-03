//
// Created by Basam on 2/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_HYPERCUBE_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_HYPERCUBE_H

#include <memory>

namespace StructuralPatterns {
    namespace Bridge {

        class HyperCubeImplementation {
        public:
            HyperCubeImplementation();
        protected:
            int dimensions{};
        private:
            int faces = 2 * dimensions;
        };

        class HyperCube {
        public:
            HyperCube();
        protected:
            std::unique_ptr<HyperCubeImplementation> implementation;
        };

        class SquareImplementation : public HyperCubeImplementation {
        public:
            SquareImplementation();
        };

        class Square : public HyperCube {
        public:
            Square();
        };

        class TessaractImplementation : public HyperCubeImplementation {
        public:
            TessaractImplementation();
        };

        class Tesseract : public HyperCube {
        public:
            Tesseract();
        };

    } // StructuralPatterns
} // Bridge

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_TESSARACTIMPLEMENTATION_H
