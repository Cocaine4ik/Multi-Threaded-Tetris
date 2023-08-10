#include "Tetromino.h"
#include "Cell.h"
#include "Board.h"

#define TETROMINO_CHAR '*'

Tetromino::Tetromino(Board* board, TetrominoType type, std::shared_ptr<Cell> startPos)
{
    this->type = type;

    isBuilt = false;

    auto posX = startPos->GetX();
    auto posY = startPos->GetY();

    switch (type)
    {
    case TetrominoType::I: 

        pivot = board->GetCell(posX +1, posY + 1);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX +1, posY),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 3)
        }; 
        break;

    case TetrominoType::S:

        pivot = board->GetCell(posX, posY + 2);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 3)
        };
        break;

    case TetrominoType::Z:

        pivot = board->GetCell(posX + 1, posY + 2);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 3)
        };
        break;

    case TetrominoType::O:

        pivot = board->GetCell(posX + 1, posY + 1);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 2)
        };
        break;

    case TetrominoType::T:

        pivot = board->GetCell(posX + 1, posY + 2);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 3)
        };
        break;

    case TetrominoType::L:

        pivot = board->GetCell(posX + 1, posY + 1);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 2),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 3)
        };
        break;

    case TetrominoType::J:

        pivot = board->GetCell(posX + 1, posY + 2);

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1),
            std::make_shared<Cell>() = pivot,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 3),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 3)
        };
        break;
    }

    for (auto cell : cells) 
    {
        cell->SetChr(TETROMINO_CHAR);
    }
}

bool Tetromino::Move(Board* board, int x, int y)
{
    nextCells.clear();
    auto nextPos = board->GetCell(pivot->GetX() + x, pivot->GetY() + y);

    for (auto& cell : cells)
    {
        // add next cells according to coordinates
        auto nextCell = board->GetCell(cell->GetX() + x, cell->GetY() + y);
        // if next cell is out of border or already built clear next cells and can't move so return false
        if (nextCell.get() == nullptr && !isBuilt)
        {
            for (auto& cell : cells)
            {
                // built tetromino only if touch down
                if (x == 0)
                {
                    board->AddBuiltCell(cell);
                    isBuilt = true;
                }
            }
            return false;
        }
        nextCells.push_back(nextCell);
    }

    // if tetromino is built - clear next cells and can't move so return false
    if (isBuilt)
    {
        nextCells.clear();
        return false;
    }

    // clear characters for cells vector
    for (auto& cell : cells)
    {
        cell->SetChr(' ');
    }

    cells = nextCells;
    pivot = nextPos;

    // set characters for new cells vector
    for (auto& cell : cells)
    {
        cell->SetChr(TETROMINO_CHAR);
    }

    return true;
}

bool Tetromino::Rotate(Board* board)
{
    if (type == TetrominoType::O) return false;

    nextRotateCells.clear();

    for (auto& cell : cells)
    {
        int x = cell->GetY() - pivot->GetY();
        int y = cell->GetX() - pivot->GetX();

        auto nextRotationCell = board->GetCell(pivot->GetX() - x, pivot->GetY() + y);

        if (nextRotationCell.get() == nullptr && !isBuilt)
        {
            for (auto& cell : cells)
            {
                // built tetromino only if touch down
                if (x == 0)
                {
                    board->AddBuiltCell(cell);
                    isBuilt = true;
                }
            }
            return false;
        }
        nextRotateCells.push_back(nextRotationCell);
    }

    // if tetromino is built - clear next cells and can't move so return false
    if (isBuilt)
    {
        nextCells.clear();
        return false;
    }

    // clear characters for cells vector
    for (auto& cell : cells)
    {
        cell->SetChr(' ');
    }

    cells = nextRotateCells;

    // set characters for new cells vector
    for (auto& cell : cells)
    {
        cell->SetChr(TETROMINO_CHAR);
    }

    return true;
}

