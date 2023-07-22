//
// Created by yuvalzo on 7/18/23.
//

#include "../include/Board.h"
#include <vector>
#include <iostream>

using namespace std;

Board::Board() {
    board = initBoard();
}


void Board::printBoard () const  {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "-------------" << std::endl;
    }
}

vector<vector<char>> Board::initBoard(char emptyMark) {
    vector<vector<char>> board
            {
                    {emptyMark, emptyMark, emptyMark},
                    {emptyMark, emptyMark, emptyMark},
                    {emptyMark, emptyMark, emptyMark}
            };
    return board;
}

bool Board::isEmptyCell(int row, int col, char mark) {
    return board[row][col] == ' ';
}


bool Board::isBoardFull(vector<vector<char>> currentBoard) {
    for (const vector<char> &rowVector: currentBoard)
        for (const char cellValue: rowVector) {
            if (cellValue == ' ')
                return false;
        }
    return true;
}
