cmake_minimum_required(VERSION 3.20)
project(Assessment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assessment2
        assessment.cpp
        assessment.h
        data_processing.cpp
        hangman_guesser.cpp
        hangman_guesser.h
        main.cpp
        main_game.cpp
        util.cpp
        util.h)
