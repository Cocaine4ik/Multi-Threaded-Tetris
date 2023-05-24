#pragma once
#include <vector>
#include <string>
#include "Cell.h"
#include "Tetromino.h"

class Board
{
private:
    std::vector<std::string> table;
    Cell spawnPos;

public:
    Board();

    void Draw();

    Tetromino* SpawnTetromino(TetrominoType type);

};

