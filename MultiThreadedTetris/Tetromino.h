#pragma once

#include <vector>
#include <string>
#include "Cell.h"

enum class TetrominoType
{
    I,
    S,
    Z,
    O,
    T,
    L,
    J
};
class Tetromino
{
private:
    TetrominoType type;
    std::vector<Cell> cells;
    Cell pos;

public:
    Tetromino(TetrominoType type, Cell startPos);
    void FallDawn();

    std::vector<Cell> GetCells() const { return cells; };

};