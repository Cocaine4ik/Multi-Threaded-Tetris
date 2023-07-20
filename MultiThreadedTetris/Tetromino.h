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
    std::vector<std::shared_ptr<Cell>> nextCells;
    std::shared_ptr<Cell> pos;

    bool isBuilt;
public:
    bool Move(Board* board, int x = 0, int y = 0);
    Tetromino(Board* board, TetrominoType type, std::shared_ptr<Cell> startPos);
    bool CheckFallDawn(Board* board);
    void FallDawn(Board* board);

    std::vector<std::shared_ptr<Cell>> GetCells() const { return cells; };

    bool IsBuilt() const { return isBuilt; }
};