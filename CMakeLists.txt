cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project src/main.cpp src/TicTacToe.cpp include/TicTacToe.h include/Board.h src/Board.cpp src/Minimax.cpp include/Minimax.h)
