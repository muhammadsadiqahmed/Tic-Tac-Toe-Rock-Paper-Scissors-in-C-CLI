#include <iostream>
using namespace std;

void Board(char *spaces) {
    system ("cls");
    cout << "         -----------\n";
    cout << "          " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << "\n";
    cout << "          " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << "\n";
    cout << "          " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << "\n";
    cout << "         -----------\n";
}

void Play(char *spaces, char marker) {
    int choose;
    cout << "Enter your choose Player " << marker << " [1-9]: ";
    cin >> choose;
    choose--;
    if (choose > -1 && choose < 9 && spaces[choose] != 'X' && spaces[choose] != 'O') {
        spaces[choose] = marker;
    } else {
        cout << "Invalid move! Try again.\n";
        Play(spaces, marker);
    }
}

bool whoWin(char *spaces, char marker) {
    if ((spaces[0] == marker && spaces[1] == marker && spaces[2] == marker) ||
        (spaces[3] == marker && spaces[4] == marker && spaces[5] == marker) ||
        (spaces[6] == marker && spaces[7] == marker && spaces[8] == marker) ||
        (spaces[0] == marker && spaces[3] == marker && spaces[6] == marker) ||
        (spaces[1] == marker && spaces[4] == marker && spaces[7] == marker) ||
        (spaces[2] == marker && spaces[5] == marker && spaces[8] == marker) ||
        (spaces[0] == marker && spaces[4] == marker && spaces[8] == marker) ||
        (spaces[2] == marker && spaces[4] == marker && spaces[6] == marker)) {
        cout << "Player " << marker << " Wins!\n";
        return true;
    }
    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] != 'X' && spaces[i] != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    char spaces[9] = {'1','2','3','4','5','6','7','8','9'};
    char marker = 'X';
    bool still = true;

    Board(spaces);
    while (still) {
        Play(spaces, marker);
        Board(spaces);
        if (whoWin(spaces, marker)) {
            still = false;
        } else if (checkTie(spaces)) {
            cout << "It's a tie!\n";
            still = false;
        }

        marker = (marker == 'X') ? 'O' : 'X';
    }

    return 0;
}