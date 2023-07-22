//
// Created by yuvalzo on 7/17/23.
//

#ifndef PROJECT_TICTACTOE_H
#define PROJECT_TICTACTOE_H


#include <string>
#include "Board.h"

class TicTacToe {
public:
    TicTacToe();
    static void computerTurn(Board& board, int row, int col);
    char checkWinner(Board &board, vector<vector<char>>& currentBoard);
    static void userTurn(Board& board);
    bool getUserTurn() const{return isUserTurn;}
    void setUserTurn(bool value){isUserTurn = value;}

private:
    bool isUserTurn = true;
    vector<vector<int>> WinCombinations{
            {0, 1, 2}, // Rows
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6}, // Columns
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8}, // Diagonals
            {2, 4, 6}
    };
};


#endif //PROJECT_TICTACTOE_H
