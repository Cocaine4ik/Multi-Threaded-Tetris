#include "Board.h"
#include <iostream>
#include "Cell.h"
#include "Tetromino.h"


#define TABLE_WIDTH 22
#define TABLE_HEIGHT 22
#define BORDER_CHAR '#'
#define TETROMINO_CHAR '*'
#define SPAWN_POS_Y 1

Board::Board() : table(TABLE_HEIGHT, std::string(TABLE_WIDTH, ' '))
{
    for (auto& str : table) 
    {
        str.front() = BORDER_CHAR;
        str.back() = BORDER_CHAR;
    }

    table.front().assign(TABLE_WIDTH, BORDER_CHAR);
    table.back().assign(TABLE_WIDTH, BORDER_CHAR);

    spawnPos.SetY(SPAWN_POS_Y);
    spawnPos.SetX(TABLE_WIDTH / 2 - 2);
}

void Board::Draw()
{
    for (auto& str : table)
    {
        std::cout << str << std::endl;
    }
}

Tetromino* Board::SpawnTetromino(TetrominoType type)
{
    Tetromino* tetromino = new Tetromino(type, Cell(spawnPos));
    
    for (auto& cell : tetromino->GetCells())
    {
        table[cell.GetY()][cell.GetX()] = TETROMINO_CHAR;
    }

    return tetromino;
}
