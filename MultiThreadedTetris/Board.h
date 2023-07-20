#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Cell.h"
#include "Tetromino.h"
#include "Board.h"

class Board
{
private:
    std::vector<std::shared_ptr<Cell>> cells;
    std::vector<std::shared_ptr<Cell>> builtCells;
    std::vector<std::shared_ptr<Cell>> borderCells;
    std::shared_ptr<Cell> spawnPos;

public:
    Board();

    void Draw();

    std::unique_ptr<Tetromino> SpawnTetromino();

    std::shared_ptr<Cell> GetCell(int x, int y) const;
    bool IsBuiltCell(std::shared_ptr<Cell> cell) const;
    bool IsBorderCell(std::shared_ptr<Cell> cell) const;
};