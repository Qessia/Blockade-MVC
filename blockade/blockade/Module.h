#pragma once


class Player;


class Gamefield {
    int rows;
    int cols;
public:
    char** matrix;

    Gamefield(int, int);

    //~Gamefield();

    void display();

    int update(Player&);

    int get_rows() {
        return rows;
    }

    int get_cols() {
        return cols;
    }
};