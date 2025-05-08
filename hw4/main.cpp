#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 畫出目前棋盤狀態
void drawBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

// 檢查是否有玩家獲勝
bool checkWin(const vector<char>& board, char player) {
    const int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // 橫排
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // 直排
        {0, 4, 8}, {2, 4, 6}             // 對角線
    };

    for (auto& combo : winCombos) {
        if (board[combo[0]] == player &&
            board[combo[1]] == player &&
            board[combo[2]] == player) {
            return true;
        }
    }
    return false;
}

// 主程式
int main() {
    vector<char> board(9);
    for (int i = 0; i < 9; ++i) board[i] = '1' + i;

    cout << "-- Tic Tac Toe -- CSIE@CGU\n";
    cout << "Player 1 (X) - Player 2 (O)\n";
    drawBoard(board);

    char currentPlayer = 'X';
    int moveCount = 0;

    while (true) {
        int move;
        while (true) {
            cout << "==> Player " << (currentPlayer == 'X' ? "1 (X)" : "2 (O)") << ", enter a number:";
            cin >> move;

            if (cin.fail() || move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
                cin.clear(); // 清除錯誤狀態
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丟棄輸入
                cout << "==> Invalid value, please enter again\n";
            } else {
                break; // 有效輸入
            }
        }

        board[move - 1] = currentPlayer;
        drawBoard(board);
        moveCount++;

        if (checkWin(board, currentPlayer)) {
            cout << "==> Player " << (currentPlayer == 'X' ? "1" : "2") << " wins!\n";
            break;
        }

        if (moveCount == 9) {
            cout << "==> Game draw\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
