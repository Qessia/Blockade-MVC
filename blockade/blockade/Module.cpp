#include "Module.h"
#include "Controller.h"

Gamefield::Gamefield(int height = 24, int width = 48) {
    // allocating memory for matrix
    rows = height;
    cols = width;
    matrix = new char* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
    }
    // adding boundaries
    for (int j = 0; j < cols; j++) {
        matrix[0][j] = '#';
        matrix[rows - 1][j] = '#';
    }
    for (int i = 1; i < rows - 1; i++) {
        matrix[i][0] = '#';
        matrix[i][cols - 1] = '#';
    }
    for (int i = 1; i < rows - 1; i++)
        for (int j = 1; j < cols - 1; j++)
            matrix[i][j] = ' ';
}

/*
Gamefield::~Gamefield() {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}*/

int Gamefield::update(Player& p) {
    std::pair<int, int> new_pos = p.step();
    if (matrix[new_pos.first][new_pos.second] != ' ') {
        p.gameOver();
        return 0;
    }
    matrix[new_pos.first][new_pos.second] = p.get_symbol();
    return 1;
}