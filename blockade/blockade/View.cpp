#include "View.h"
#include "Controller.h"
#include "Module.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void Gamefield::display() {
    system("cls");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j];
        cout << endl;
    }
}


void Player::gameOver() {
    system("cls");
    ifstream fin(number == 2 ? "win1.txt" : "win2.txt");
    while (fin) {
        string strInput;
        getline(fin, strInput, '\n');
        cout << strInput << endl;
    }
    char key = getch();
    do {
        key = getch();
    } while (key != 27);
    fin.close();
}