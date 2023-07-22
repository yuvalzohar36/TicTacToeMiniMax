//
// Created by yuvalzo on 7/17/23.
//

#include "../include/TicTacToe.h"
#include "../include/Utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

vector<int> locationToIndexes(int location) {
    return vector<int>{
            static_cast<int>(location / 3), location % 3
    };
}

TicTacToe::TicTacToe() {};

char TicTacToe::checkWinner(Board &board, vector<vector<char>>& currentBoard) {
//    vector<vector<char>> currentBoard = board.getBoard();
    for (vector<int> winVector: WinCombinations) {
        vector<int> winIndexes0, winIndexes1, winIndexes2;
        winIndexes0 = locationToIndexes(winVector[0]);
        winIndexes1 = locationToIndexes(winVector[1]);
        winIndexes2 = locationToIndexes(winVector[2]);
        if (currentBoard[winIndexes0[0]][winIndexes0[1]] == currentBoard[winIndexes1[0]][winIndexes1[1]] &&
            currentBoard[winIndexes1[0]][winIndexes1[1]] == currentBoard[winIndexes2[0]][winIndexes2[1]] &&
            currentBoard[winIndexes0[0]][winIndexes0[1]] != ' ') {
            return currentBoard[winIndexes0[0]][winIndexes0[1]];
        }
    }
    if(board.isBoardFull(currentBoard)) {
        return 'E';
    }
    return ' ';
}



void TicTacToe::computerTurn(Board& board) {
    int row, col;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    do{
        row = Utils::getRandomNumber(0, 2);
        col = Utils::getRandomNumber(0, 2);
    }
    while(!board.isEmptyCell(row, col));
    board.getBoard()[row][col] = 'O';
    cout << "Board after computer turn :\n";
}

void TicTacToe::userTurn(Board& board) {
    bool isOccupiedInserted = false;
    int location;
    vector<int> rowColVector;
    vector<vector<char>>& currentBoard = board.getBoard();
    do{
        if(isOccupiedInserted)
            cout << "You entered an occupied location, please choose again \n" << endl;
        cout << "Enter number of cell (0-9)\n\n" << endl;
        cin  >> location;
        rowColVector = locationToIndexes(location);
        isOccupiedInserted = true;
    }
    while(!board.isEmptyCell(rowColVector[0], rowColVector[1]));
    currentBoard[rowColVector[0]][rowColVector[1]] = 'X';
}

