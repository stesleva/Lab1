// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

// Глобальные переменные
vector<vector<char>> board(3, vector<char>(3, ' ')); // Игровое поле 3x3

// Функция для отображения игрового поля
void displayBoard() {
    cout << "  1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1;
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "  ---------\n";
    }
}

// Функция для проверки, выиграл ли игрок
bool checkWin(char player) {
    // Проверка горизонталей, вертикалей и диагоналей
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Функция для проверки ничьей
bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Добро пожаловать в игру Крестики-Нолики!" << endl;

    while (!gameOver) {
        displayBoard();
        int row, col;

        // Ввод координат от текущего игрока
        cout << "Игрок " << currentPlayer << ", введите строку (1-3) и столбец (1-3): ";
        cin >> row >> col;

        // Проверка валидности ввода
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Неверные координаты. Попробуйте снова." << endl;
            continue;
        }

        // Установка символа игрока на доске
        board[row - 1][col - 1] = currentPlayer;

        // Проверка выигрыша или ничьи
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Игрок " << currentPlayer << " победил! Поздравляем!" << endl;
            gameOver = true;
        }
        else if (checkTie()) {
            displayBoard();
            cout << "Ничья! Игра завершена." << endl;
            gameOver = true;
        }

        // Переключение к следующему игроку
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}


