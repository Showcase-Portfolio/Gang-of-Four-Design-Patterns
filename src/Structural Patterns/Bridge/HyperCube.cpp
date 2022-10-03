//
// Created by Basam on 2/10/2022.
//

#include "HyperCube.h"
#include <iostream>

namespace StructuralPatterns {
    namespace Bridge {
        HyperCubeImplementation::HyperCubeImplementation() = default;

        HyperCube::HyperCube() = default;

        SquareImplementation::SquareImplementation() {
            dimensions = 2;
        }

        Square::Square() {
            std::cout << "Created Square" << std::endl;
            implementation = std::unique_ptr<SquareImplementation>(new SquareImplementation());
        }

        TessaractImplementation::TessaractImplementation() {
            dimensions = 4;
        }

        Tesseract::Tesseract() {
            std::cout << "Created Tesseract" << std::endl;
            implementation = std::unique_ptr<TessaractImplementation>(new TessaractImplementation());
        }
    } // StructuralPatterns
} // Bridge