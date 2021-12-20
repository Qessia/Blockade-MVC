#include "Controller.h"
#include "Module.h"
#include <ctime>
#include <map>
#include <windows.h>

using namespace std;


class Gamefield;

const string dirs = "URDL";

char enumeration = 1;

Player::Player(Gamefield g, bool mod, char symb, string ctrls) {
    number = enumeration++;
    pos = make_pair(g.get_rows() / 4, g.get_cols() / 4);
    if (number == 2) {
        pos.first *= 3;
        pos.second *= 3;
    }
    dir = dirs[rand() % 4];
    symbol = symb;
    mode = mod;
    controls = ctrls;
}


pair<int, int> Player::step() {
    if (dir == 'U')
        pos.first--;
    else if (dir == 'R')
        pos.second++;
    else if (dir == 'D')
        pos.first++;
    else if (dir == 'L')
        pos.second--;
    return pos;
}


void Player::set_dir(Gamefield g) {
    if (!mode) {
        if (GetAsyncKeyState(controls[0]) && (dir != 'D')) {
            dir = 'U';
        }
        if (GetAsyncKeyState(controls[1]) && dir != 'L') {
            dir = 'R';
        }
        if (GetAsyncKeyState(controls[2]) && dir != 'U') {
            dir = 'D';
        }
        if (GetAsyncKeyState(controls[3]) && dir != 'R') {
            dir = 'L';
        }
    }
    else {
        dir = compute(g);
    }

}


char Player::compute(Gamefield g) {
    map<char, int> ranges = {
        {'U', 0},
        {'R', 0},
        {'D', 0},
        {'L', 0}
    };
    for (int i = pos.first - 1; i > 0; i--) {
        if (g.matrix[i][pos.second] != ' ')
            break;
        ranges['U']++;
    }
    for (int i = pos.second + 1; i < g.get_cols(); i++) {
        if (g.matrix[pos.first][i] != ' ')
            break;
        ranges['R']++;
    }
    for (int i = pos.first + 1; i < g.get_rows(); i++) {
        if (g.matrix[i][pos.second] != ' ')
            break;
        ranges['D']++;
    }
    for (int i = pos.second - 1; i > 0; i--) {
        if (g.matrix[pos.first][i] != ' ')
            break;
        ranges['L']++;
    }
    // key with max map value
    char d = 'U';
    if (ranges[d] < ranges['R'])
        d = 'R';
    if (ranges[d] < ranges['D'])
        d = 'D';
    if (ranges[d] < ranges['L'])
        d = 'L';

    //save from going backside
    if ((dir == 'U') && (d == 'D') ||
        (dir == 'R') && (d == 'L') ||
        (dir == 'D') && (d == 'U') ||
        (dir == 'L') && (d == 'R'))
        d = dir;

    return d;
}