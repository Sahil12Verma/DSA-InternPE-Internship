#include <iostream>
#include <vector>
using namespace std;
const int ROWS = 6;
const int COLS = 7;
class ConnectFour {
private:
    vector<vector<char>> board;
    char currentPlayer;
public:
    ConnectFour() : board(ROWS, vector<char>(COLS, '.')), currentPlayer('X') {}
    void printBoard() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "1 2 3 4 5 6 7" << endl;
    }
    bool isColumnFull(int col) {
        return board[0][col] != '.';
    }
    bool makeMove(int col) {
        if (col < 1 || col > COLS || isColumnFull(col - 1)) {
            cout << "Invalid move. Try again." << endl;
            return false;
        }
        int row = ROWS - 1;
        while (board[row][col - 1] != '.' && row >= 0) {
            --row;
        }
        board[row][col - 1] = currentPlayer;

        return true;
    }
    bool checkWin() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                if (board[i][j] != '.' &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] &&
                    board[i][j] == board[i][j + 3]) {
                    return true;
                }
            }
        }
        for (int i = 0; i < ROWS - 3; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] != '.' &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] &&
                    board[i][j] == board[i + 3][j]) {
                    return true;
                }
            }
        }
        for (int i = 0; i < ROWS - 3; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                if (board[i][j] != '.' &&
                    board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2] &&
                    board[i][j] == board[i + 3][j + 3]) {
                    return true;
                }
            }
        }
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                if (board[i][j] != '.' &&
                    board[i][j] == board[i - 1][j + 1] &&
                    board[i][j] == board[i - 2][j + 2] &&
                    board[i][j] == board[i - 3][j + 3]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    ConnectFour game;
    do {
        game.printBoard();
        int column;
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (1-7): ";
        cin >> column;
        if (game.makeMove(column)) {
            if (game.checkWin()) {
                game.printBoard();
                cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
                break;
            }
            if (game.isBoardFull()) {
                game.printBoard();
                cout << "The game is a draw." << endl;
                break;
            }
            game.switchPlayer();
        }
    } while (true);

    return 0;
}
