#include "Tetromino.h"
#include "Cell.h"
#include "Board.h"

#define TETROMINO_CHAR '*'
#define TETROMINO_OFFSET 1
#define TETROMINO_I_OFFSET 2

Tetromino::Tetromino(Board* board, TetrominoType type, std::shared_ptr<Cell> startPos)
{
    this->type = type;
    this->pos = startPos;

    isBuilt = false;

    auto posX = pos->GetX();
    auto posY = pos->GetY();

    switch (type)
    {
    case TetrominoType::I: 

        posX -= TETROMINO_I_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 3, posY)
        }; 
        break;

    case TetrominoType::S:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX - 1, posY + 1)
        };
        break;

    case TetrominoType::Z:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX - 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::O:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::T:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::L:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1)
        };
        break;

    case TetrominoType::J:

        posX -= TETROMINO_OFFSET;

        cells =
        {
            std::make_shared<Cell>() = board->GetCell(posX, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY + 1)
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

    for (auto& cell : cells)
    {
        // add next cells according to coordinates
        auto nextCell = board->GetCell(cell->GetX() + x, cell->GetY() + y);

        // if next cell is out of border or already built clear next cells and can't move so return false
        if (nextCell.get() == nullptr && !isBuilt)
        {
            for (auto& cell : cells)
            {
                board->AddBuiltCell(cell);
                isBuilt = true;
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

    // set characters for new cells vector
    for (auto& cell : cells)
    {
        cell->SetChr(TETROMINO_CHAR);
    }
    
    nextCells.clear();

    return true;
}

bool Tetromino::Rotate(Board* board)
{
    nextRotateCells.clear();

    return false;
}

