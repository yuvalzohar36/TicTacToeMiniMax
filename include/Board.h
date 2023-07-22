//
// Created by yuvalzo on 7/18/23.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include <string>
#include <vector>
using namespace std;

class Board{
public:
    Board();
    vector<vector<char>>& getBoard(){return board;}
    static bool isBoardFull(vector<vector<char>> currentBoard);
    void printBoard() const;
    bool isEmptyCell(int row, int col, char mark = ' ');
    static vector<vector<char>> initBoard(char emptyMark = ' ');
private:
    vector<vector<char>> board;


};
#endif //PROJECT_BOARD_H

