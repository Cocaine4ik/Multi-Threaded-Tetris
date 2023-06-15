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

void Tetromino::FallDawn(Board* board)
{
    for (auto& cell : cells)
    {
        cell = board->GetCell(cell->GetX(), cell->GetY() + 1);
    }
}
