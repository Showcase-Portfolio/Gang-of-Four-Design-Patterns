cmake_minimum_required(VERSION 3.24)
project(Gang_of_Four_Design_Patterns)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

add_executable(Gang_of_Four_Design_Patterns
        src/main.cpp "src/Creational Patterns/Abstract Factory/MedicineManufacturing.h" "src/Creational Patterns/Abstract Factory/MedicineManufacturing.cpp" "src/Creational Patterns/Builder/ChessPositions.h" "src/Creational Patterns/Builder/ChessPositions.cpp" "src/Creational Patterns/Factory/Humanoid.cpp" "src/Creational Patterns/Prototype/Laptop.h" "src/Creational Patterns/Prototype/Laptop.cpp" "src/Creational Patterns/Singleton/AppConfig.h" "src/Creational Patterns/Singleton/AppConfig.cpp" "src/Structural Patterns/Adapter/ApiWrapper.h" "src/Structural Patterns/Adapter/ApiWrapper.cpp" "src/Structural Patterns/Bridge/HyperCube.h" "src/Structural Patterns/Bridge/HyperCube.cpp" "src/Structural Patterns/Composite/Actuator.h" "src/Structural Patterns/Composite/Actuator.cpp" "src/Structural Patterns/Decorator/Interaction.h" "src/Structural Patterns/Decorator/Interaction.cpp")
