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
    std::vector<std::shared_ptr<Cell>> built_cells;
    std::shared_ptr<Cell> spawnPos;

public:
    Board();

    void Draw();

    std::unique_ptr<Tetromino> SpawnTetromino(TetrominoType type);

    std::shared_ptr<Cell> GetCell(int x, int y) const;

};

