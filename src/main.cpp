#include <iostream>
#include "../include/TicTacToe.h"

#define EMPTY_CELL ' '

#include <climits>

pair<int, pair<int, int>>
maxValue(TicTacToe& ticTacToe, Board& board, vector<vector<char>> currentBoard, char myMark = 'X');

pair<int, pair<int, int>>
minValue(TicTacToe& ticTacToe, Board& board, vector<vector<char>> currentBoard, char myMark = 'X');

void computerTurn(Board &board, int row, int col);

pair<int, pair<int, int>>


value(TicTacToe& ticTacToe, Board& board, vector<vector<char>> currentBoard, char myMark = 'X', bool calledByMax = true) {
    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == 'X') {
            return make_pair(1, make_pair(-1, -1));
        } else if (winner == 'E') {
            return make_pair(0, make_pair(-1, -1));
        }
        return make_pair(-1, make_pair(-1, -1));
    }
    if (calledByMax) {
        return maxValue(ticTacToe, board, currentBoard, myMark);
    }
    return minValue(ticTacToe, board, currentBoard, myMark);
}
pair<int, pair<int, int>> maxValue(TicTacToe& ticTacToe, Board& board, vector<vector<char>> currentBoard, char myMark) {
    int val = INT_MIN;
    int maxRowValI = 0;
    int maxColValJ = 0;
    char opponentMark = (myMark == 'X') ? 'O' : 'X'; // Determine opponent's mark

    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == 'X') {
            return make_pair(-1, make_pair(-1, -1));
        } else if (winner == 'E') {
            return make_pair(0, make_pair(-1, -1));
        }
        return make_pair(1, make_pair(-1, -1));
    }

    for (int rowI = 0; rowI < currentBoard.size(); rowI++) {
        for (int colJ = 0; colJ < currentBoard[rowI].size(); colJ++) {
            if (currentBoard[rowI][colJ] == ' ') {
                currentBoard[rowI][colJ] = myMark;
                int curValue = minValue(ticTacToe, board, currentBoard, opponentMark).first; // Opponent's turn
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

pair<int, pair<int, int>> minValue(TicTacToe& ticTacToe, Board& board, vector<vector<char>> currentBoard, char myMark) {
    int val = INT_MAX;
    int minRowValI = 0;
    int minColValJ = 0;
    char opponentMark = (myMark == 'X') ? 'O' : 'X'; // Determine opponent's mark

    char winner = ticTacToe.checkWinner(board, currentBoard);
    if (winner != EMPTY_CELL) {
        if (winner == 'X') {
            return make_pair(-1, make_pair(-1, -1));
        } else if (winner == 'E') {
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


int main() {
    vector<vector<char>> currentBoard;
    pair<int, pair<int, int>> bestScoreMove;
    char winner = ' ';
    bool isUserTurn;
    TicTacToe ticTacToeInstance;
    Board board;
    currentBoard = board.getBoard();
    board.printBoard();
    while (winner == ' ') {
        isUserTurn = ticTacToeInstance.getUserTurn();
        if (isUserTurn)
            ticTacToeInstance.userTurn(board);
        else {
            cout << "NOW IM HERE\n";
            bestScoreMove = value(ticTacToeInstance, board, currentBoard, 'O', true);
            cout << bestScoreMove.second.first << bestScoreMove.second.second << endl;
            computerTurn(board, bestScoreMove.second.first, bestScoreMove.second.second);
        }
        ticTacToeInstance.setUserTurn(!isUserTurn);
        currentBoard = board.getBoard();
        winner = ticTacToeInstance.checkWinner(board, currentBoard);
        board.printBoard();
    }
    switch (winner) {
        case 'E':
            cout << "Even, Nice game ! \n";
            break;
        case 'X':
            cout << "X (You) won, great job ! \n";
            break;
        default:
            cout << "O (Computer) won LOL \n";
            break;
    }

    return 0;
}





void computerTurn(Board &board, int row, int col) {
    board.getBoard()[row][col] = 'O';
    cout << "Board after computer turn :\n";
}
