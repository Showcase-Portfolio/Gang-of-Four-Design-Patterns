cmake_minimum_required(VERSION 3.24)
project(Gang_of_Four_Design_Patterns)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

add_executable(Gang_of_Four_Design_Patterns
        src/main.cpp "src/Creational Patterns/Abstract Factory/MedicineManufacturing.h" "src/Creational Patterns/Abstract Factory/MedicineManufacturing.cpp" "src/Creational Patterns/Builder Design Pattern/ChessPositions.h" "src/Creational Patterns/Builder Design Pattern/ChessPositions.cpp")
