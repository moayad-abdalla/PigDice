cmake_minimum_required(VERSION 3.20)
project(PigDiceMultiplayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PigDiceMultiplayer
        PigDice.cpp
        DIE.cpp
        Turn.cpp
        PDGame.cpp
        PDGameV2.cpp
        PDGameV2.h
        PDGameV2.cpp
)