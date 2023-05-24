#pragma once

#include <vector>
#include <string>
#include <memory>
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
    std::vector<std::shared_ptr<Cell>> cells;
    std::shared_ptr<Cell> pos;

public:
    Tetromino(TetrominoType type, Cell startPos);
    void FallDawn();

    std::vector<Cell> GetCells() const { return cells; };

};