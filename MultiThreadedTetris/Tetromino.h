#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Cell.h"

class Board;

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
    Tetromino(Board* board, TetrominoType type, std::shared_ptr<Cell> startPos);
    void FallDawn(Board* board);

    std::vector<std::shared_ptr<Cell>> GetCells() const { return cells; };

};