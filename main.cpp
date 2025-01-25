#include <iostream>
using namespace std;

void displayBoard(const char board[3][3]);

bool checkWin(const char board[3][3], char player);

bool isBoardFull(const char board[3][3]);

int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    int row, col;
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player X and Player O\n";
    displayBoard(board);
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column between 0 and 2): ";
        std::cout << "\nEnter row : ";
        cin >> row;
        std::cout << "\nEnter colum : ";
        cin >> col;

        if (row < 0 || col < 0 || row >= 3 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid Input\n";
            continue;
        }
        board[row][col] = currentPlayer;
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isBoardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void displayBoard(const char board[3][3]) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << endl;
}

bool checkWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isBoardFull(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
