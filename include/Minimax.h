//
// Created by yuvalzo on 7/22/23.
//

#ifndef PROJECT_MINIMAX_H
#define PROJECT_MINIMAX_H


#include "TicTacToe.h"

#define EMPTY_CELL ' '
#define XMARK 'X'
#define OMARK 'O'
#define EVEN 'E'

class Minimax {
public:
    static pair<int, pair<int, int>>
    value(TicTacToe
          &ticTacToe,
          Board &board, vector<vector<char>>
          currentBoard,
          char myMark = XMARK,
          bool calledByMax = true
    );

    static pair<int, pair<int, int>>
    maxValue(TicTacToe &ticTacToe, Board &board, vector<vector<char>> currentBoard, char myMark = XMARK);

    static pair<int, pair<int, int>>
    minValue(TicTacToe &ticTacToe, Board &board, vector<vector<char>> currentBoard, char myMark = XMARK);

};


#endif //PROJECT_MINIMAX_H
