#include "main.h"
#include "Controller.h"
#include "Module.h"
#include "View.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {

    Gamefield g(24, 48);
    Player p1(g, 0, 'O', "WDSA");
    Player p2(g, 0, '@', "ILKJ");
    ifstream sel("select.txt");
    while (sel) {
        string strInput;
        getline(sel, strInput, '\n');
        cout << strInput << endl;
    }
    while (1) {
        char key = getch();
        if (key == 'b') {
            p2.set_mode(1);
            p2.set_symbol('0');
            break;
        }
        if (key == 'p') {
            break;
        }
    }
    g.display();
    while (g.update(p1) && g.update(p2)) {
        g.display();
        p1.set_dir(g);
        p2.set_dir(g);
        Sleep(30);
    }

    return 0;
}