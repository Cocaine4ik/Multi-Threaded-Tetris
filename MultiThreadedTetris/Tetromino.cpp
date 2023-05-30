#include "Tetromino.h"
#include "Cell.h"
#include "Board.h"

#define TETROMINO_CHAR '*'

Tetromino::Tetromino(Board* board, TetrominoType type, std::shared_ptr<Cell> startPos)
{
    this->type = type;
    this->pos = startPos;

    auto posX = pos->GetX();
    auto posY = pos->GetY();

    switch (type)
    {
    case TetrominoType::I: 
        cells = 
        {
            pos,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 3, posY)
        }; 
        break;

    case TetrominoType::S:
        cells =
        {
            pos, 
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX - 1, posY + 1)
        };
        break;

    case TetrominoType::Z:
        cells =
        {
            pos,
            std::make_shared<Cell>() = board->GetCell(posX - 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::O:
        cells =
        {
            pos,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::T:
        cells =
        {
            pos,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::L:
        cells =
        {
            pos,
            std::make_shared<Cell>() = board->GetCell(posX + 1, posY),
            std::make_shared<Cell>() = board->GetCell(posX + 2, posY),
            std::make_shared<Cell>() = board->GetCell(posX, posY + 1)
        };
        break;

    case TetrominoType::J:
        cells =
        {
            pos,
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

void Tetromino::FallDawn()
{
    for (auto& cell : cells)
    {
        cell->MoveY(cell->GetY() + 1);
    }
}
