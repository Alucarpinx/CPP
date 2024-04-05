#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function
#include <windows.h> // For Windows-specific functions

using namespace std;

// Function to clear the screen
void clearScreen() {
    system("cls");
}

void welcome(int& selecter) {
    cout << "              Welcome to Connect4            " << endl;
    cout << "      The goal of Connect4 is to be the first     " << endl;
    cout << " player to place four checkers in a row, either" << endl;
    cout << "    horizontally, vertically, or diagonally.    " << endl << endl;

    int playerSelection = rand() % 2;
    if (playerSelection == 0) {
        selecter = 1;
    }
    else {
        selecter = 0;
    }
}

void initGrid(char grid[][7], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 7; j++) {
            grid[i][j] = ' ';
        }
    }
}

void displayGrid(char grid[][7], int row) {
    cout << "        ";
    for (int i = 0; i < 7; i++) {
        cout << "  " << (i + 1) << " ";
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        cout << "        ";
        for (int j = 0; j < 7; j++) {
            cout << "| " << grid[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "        ";
        for (int j = 0; j < 7; j++) {
            cout << "+---";
        }
        cout << "+" << endl;
    }
}

void fillGrid(char grid[][7], int row, char sym, int col) {
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col - 1] == ' ') {
            grid[i][col - 1] = sym;
            return;
        }
    }
}

bool gameOver(char grid[][7], int rowCnt, char currentPlayer) {
    char opponent = (currentPlayer == 'x') ? 'o' : 'x';

    // Horizontal check
    for (int row = 0; row < rowCnt; row++) {
        for (int col = 0; col < 4; col++) {
            if (grid[row][col] == currentPlayer && grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row][col + 2] && grid[row][col] == grid[row][col + 3]) {
                return true;
            }
        }
    }
    // Vertical check
    for (int col = 0; col < 7; col++) {
        for (int row = 0; row < rowCnt - 3; row++) {
            if (grid[row][col] == currentPlayer && grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row + 2][col] && grid[row][col] == grid[row + 3][col]) {
                return true;
            }
        }
    }
    // Diagonal (start) check
    for (int row = 0; row < rowCnt - 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (grid[row][col] == currentPlayer && grid[row][col] == grid[row + 1][col + 1] && grid[row][col] == grid[row + 2][col + 2] && grid[row][col] == grid[row + 3][col + 3]) {
                return true;
            }
        }
    }
    // Diagonal (end) check
    for (int row = 0; row < rowCnt - 3; row++) {
        for (int col = 3; col < 7; col++) {
            if (grid[row][col] == currentPlayer && grid[row][col] == grid[row + 1][col - 1] && grid[row][col] == grid[row + 2][col - 2] && grid[row][col] == grid[row + 3][col - 3]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    bool checkPlayer1 = false, checkPlayer2 = false;
    int check = 0;
    bool balance = true;
    while (balance) {
        welcome(check);
        if (check == 1) {
            cout << "              Player #1 selected" << endl;
            checkPlayer1 = true;
        }
        else {
            cout << "              Player #2 selected" << endl;
            checkPlayer2 = true;
        }
        balance = false;
    }

    char grid[6][7];
    char player1 = 'x', player2 = 'o';
    char choice;
    int col;

    while (true) {
        initGrid(grid, 6);
        displayGrid(grid, 6);
        while (true) {
            if (checkPlayer1) {
                cout << "     Player #1 Turn (x): Enter your move (1-7): ";
                cin >> col;
                while (col < 1 || col > 7 || grid[0][col - 1] != ' ') {
                    cout << "     Invalid choice! Please enter a valid column (1-7): ";
                    cin >> col;
                }
                fillGrid(grid, 6, player1, col);
                clearScreen();
                displayGrid(grid, 6);
                if (gameOver(grid, 6, player1)) {
                    cout << "     Game over! Player #1 (x) wins!" << endl;
                    break;
                }
                checkPlayer1 = false;
                checkPlayer2 = true;
            }
            else if (checkPlayer2) {
                cout << "     Player #2 Turn (o): Enter your move (1-7): ";
                cin >> col;
                while (col < 1 || col > 7 || grid[0][col - 1] != ' ') {
                    cout << "     Invalid choice! Please enter a valid column (1-7): ";
                    cin >> col;
                }
                fillGrid(grid, 6, player2, col);
                clearScreen();
                displayGrid(grid, 6);
                if (gameOver(grid, 6, player2)) {
                    cout << "     Game over! Player #2 (o) wins!" << endl;
                    break;
                }
                checkPlayer2 = false;
                checkPlayer1 = true;
            }
        }
        cout << "     Do you want to play again (y/n)? ";
        cin >> choice;
        if (choice == 'n') {
            break;
        }
        checkPlayer1 = false;
        checkPlayer2 = false;
    }
    return 0;
}
