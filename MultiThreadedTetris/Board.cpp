#include "Board.h"
#include <iostream>
#include <memory>
#include "Cell.h"
#include "Tetromino.h"
#include <algorithm>

#define TABLE_WIDTH 22
#define TABLE_HEIGHT 22
#define BORDER_CHAR '#'
#define SPAWN_POS_Y 1

Board::Board()
{
    for (int y = 0; y < TABLE_HEIGHT; y++)
    {
        for (int x = 0; x < TABLE_WIDTH; x++)
        {
            auto cell = std::make_shared<Cell>(x, y);
            cells.push_back(cell);
        }
    }

    for (auto cell : cells)
    {
        if (cell->GetX() == 0 || cell->GetY() == 0 || 
            cell->GetX() == TABLE_WIDTH - 1 || cell->GetY() == TABLE_HEIGHT - 1)
        {
            cell->SetChr(BORDER_CHAR);
        }
    }

    spawnPos = GetCell(TABLE_WIDTH / 2, SPAWN_POS_Y);
}

void Board::Draw()
{
    int previousY = cells.front()->GetY();

    for (auto cell : cells)
    {
        if (cell->GetY() != previousY)
        {
            previousY = cell->GetY();
            std::cout << std::endl;
        }
        std::cout << cell->GetChr();
    }
}

std::unique_ptr<Tetromino> Board::SpawnTetromino(TetrominoType type)
{
    auto tetromino = std::make_unique<Tetromino>(this, type, spawnPos);
    
    return tetromino;
}

std::shared_ptr<Cell> Board::GetCell(int x, int y) const
{
    auto result = std::find_if(cells.cbegin(), cells.cend(), [x, y](const std::shared_ptr<Cell>& cell)
        {
            return cell->GetX() == x && cell->GetY() == y;
        });
    if (result != cells.cend())
    {
        return *result;
    }
    return nullptr;
}
