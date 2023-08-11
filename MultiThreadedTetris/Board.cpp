#include "Board.h"
#include <iostream>
#include <memory>
#include "Cell.h"
#include "Tetromino.h"
#include <algorithm>
#include <random>
#include <unordered_set>

#define TABLE_WIDTH 12
#define TABLE_HEIGHT 18
#define BORDER_CHAR '*'
#define SPAWN_POS_Y 1
#define SPAWN_POS_MARGIN 1

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

            borderCells.push_back(cell);
        }
    }

    spawnPos = GetCell(TABLE_WIDTH / 2 - SPAWN_POS_MARGIN, SPAWN_POS_Y);
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

std::unique_ptr<Tetromino> Board::SpawnTetromino()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    auto randomNumber = std::uniform_int_distribution<int>(0, 6)(gen);
    TetrominoType randomType = static_cast<TetrominoType>(randomNumber);

    auto tetromino = std::make_unique<Tetromino>(this, randomType, spawnPos);
    
    // random tetromino rotation
    auto randomRotationCount = std::uniform_int_distribution<int>(0, 3)(gen);
    
    for (int i = 0; i < randomRotationCount; i++)
    {
       tetromino->Rotate(this);
    }

    return tetromino;
}

std::shared_ptr<Cell> Board::GetCell(int x, int y) const
{
    auto result = std::find_if(cells.cbegin(), cells.cend(), [x, y](const std::shared_ptr<Cell>& cell)
        {
            return cell->GetX() == x && cell->GetY() == y;
        });

    if (result != cells.cend() && !IsBuiltCell(*result) && !IsBorderCell(*result))
    {
        return *result;
    }
    return nullptr;
}

bool Board::IsBuiltCell(std::shared_ptr<Cell> cell) const
{
    auto it = std::find(builtCells.cbegin(), builtCells.cend(), cell);

    if (it != builtCells.cend()) return true;

    return false;
}

bool Board::IsBorderCell(std::shared_ptr<Cell> cell) const
{
    auto it = std::find(borderCells.cbegin(), borderCells.cend(), cell);

    if (it != borderCells.cend()) return true;

    return false;
}

void Board::AddBuiltCell(std::shared_ptr<Cell> cell)
{
    builtCells.push_back(cell);
}

void Board::ClearBuiltCells()
{
    auto compareByY = [](const std::shared_ptr<Cell>& cell1, 
        const std::shared_ptr<Cell>& cell2)
    {
        return cell1->GetY() == cell2->GetY();
    };

    std::unordered_set<std::shared_ptr<Cell>, decltype(compareByY)> uniqueLines(0, compareByY);

    for (const auto& cell : builtCells)
    {
        uniqueLines.insert(cell);
    }

    for (const auto& cell : uniqueLines)
    {
        const int targetY = cell->GetY();

        int count = std::count_if(builtCells.begin(), builtCells.end()),
            [targetY](const std::shared_ptr<Cell> cell)
        {
            return cell->GetY() == targetY;
        });

        if (count == 10)
        {

        }
    }
}
