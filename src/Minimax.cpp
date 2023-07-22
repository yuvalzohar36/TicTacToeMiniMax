//
// Created by yuvalzo on 7/22/23.
//

#include <climits>
#include "../include/Minimax.h"
#include "../include/TicTacToe.h"

pair<int, pair<int, int>>
Minimax::value(TicTacToe &ticTacToe, Board &board, vector<vector<char>> currentBoard, char myMark, bool calledByMax) {
    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == XMARK) {
            return make_pair(1, make_pair(-1, -1));
        } else if (winner == EVEN) {
            return make_pair(0, make_pair(-1, -1));
        }
        return make_pair(-1, make_pair(-1, -1));
    }
    if (calledByMax) {
        return Minimax::maxValue(ticTacToe, board, currentBoard, myMark);
    }
    return Minimax::minValue(ticTacToe, board, currentBoard, myMark);
}

pair<int, pair<int, int>>
Minimax::maxValue(TicTacToe &ticTacToe, Board &board, vector<vector<char>> currentBoard, char myMark) {
    int val = INT_MIN;
    int maxRowValI = 0;
    int maxColValJ = 0;
    char opponentMark = (myMark == XMARK) ? OMARK : XMARK; // Determine opponent's mark

    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == XMARK) {
            return make_pair(-1, make_pair(-1, -1));
        } else if (winner == EVEN) {
            return make_pair(0, make_pair(-1, -1));
        }
        return make_pair(1, make_pair(-1, -1));
    }

    for (int rowI = 0; rowI < currentBoard.size(); rowI++) {
        for (int colJ = 0; colJ < currentBoard[rowI].size(); colJ++) {
            if (currentBoard[rowI][colJ] == ' ') {
                currentBoard[rowI][colJ] = myMark;
                int curValue = Minimax::minValue(ticTacToe, board, currentBoard, opponentMark).first; // Opponent's turn
                if (curValue > val) {
                    val = curValue;
                    maxRowValI = rowI;
                    maxColValJ = colJ;
                }
                currentBoard[rowI][colJ] = ' ';
            }
        }
    }
    return make_pair(val, make_pair(maxRowValI, maxColValJ));
}

pair<int, pair<int, int>>
Minimax::minValue(TicTacToe &ticTacToe, Board &board, vector<vector<char>> currentBoard, char myMark) {
    int val = INT_MAX;
    int minRowValI = 0;
    int minColValJ = 0;
    char opponentMark = (myMark == XMARK) ? OMARK : XMARK; // Determine opponent's mark

    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == XMARK) {
            return make_pair(-1, make_pair(-1, -1));
        } else if (winner == EVEN) {
            return make_pair(0, make_pair(-1, -1));
        }
        return make_pair(1, make_pair(-1, -1));
    }

    for (int rowI = 0; rowI < currentBoard.size(); rowI++) {
        for (int colJ = 0; colJ < currentBoard[rowI].size(); colJ++) {
            if (currentBoard[rowI][colJ] == ' ') {
                currentBoard[rowI][colJ] = myMark;
                int curValue = maxValue(ticTacToe, board, currentBoard, opponentMark).first; // Opponent's turn
                if (curValue < val) {
                    val = curValue;
                    minRowValI = rowI;
                    minColValJ = colJ;
                }
                currentBoard[rowI][colJ] = ' ';
            }
        }
    }
    return make_pair(val, make_pair(minRowValI, minColValJ));
}