#include <iostream>
#include "../include/TicTacToe.h"

#define EMPTY_CELL ' '

#include <climits>
#include "../include/Minimax.h"

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
            bestScoreMove = Minimax::value(ticTacToeInstance, board, currentBoard, OMARK, true);
            cout << bestScoreMove.second.first << bestScoreMove.second.second << endl;
            ticTacToeInstance.computerTurn(board, bestScoreMove.second.first, bestScoreMove.second.second);
        }
        ticTacToeInstance.setUserTurn(!isUserTurn);
        currentBoard = board.getBoard();
        winner = ticTacToeInstance.checkWinner(board, currentBoard);
        board.printBoard();
    }
    switch (winner) {
        case EVEN:
            cout << "EVEN, Nice game ! \n";
            break;
        case XMARK:
            cout << "X (You) won, great job ! \n";
            break;
        default:
            cout << "O (Computer) won LOL \n";
            break;
    }
    return 0;
}

