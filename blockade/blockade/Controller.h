#pragma once

#include <string>


class Gamefield;


class Player {
private:
    std::pair<int, int> pos;
    char number;
    char dir;
    bool mode;
    char symbol;
    std::string controls;

public:
    Player(Gamefield, bool, char, std::string);

    std::pair<int, int> step();

    void gameOver();

    char get_symbol() {
        return symbol;
    }

    std::pair<int, int> get_pos() {
        return pos;
    }

    void set_dir(Gamefield);

    void set_mode(int mod) {
        mode = mod;
    }

    void set_symbol(char s) {
        symbol = s;
    }

    char compute(Gamefield);
};