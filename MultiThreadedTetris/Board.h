#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Cell.h"
#include "Tetromino.h"

class Board
{
private:
    std::vector<std::shared_ptr<Cell>> cells;
    std::vector<std::shared_ptr<Cell>> built_cells;
    std::vector<std::string> table;
    Cell spawnPos;

public:
    Board();

    void Draw();

    Tetromino* SpawnTetromino(TetrominoType type);

};

