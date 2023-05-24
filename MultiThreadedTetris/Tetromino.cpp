#include "Tetromino.h"
#include "Cell.h"

Tetromino::Tetromino(TetrominoType type, Cell startPos)
{
    this->type = type;
    this->pos = startPos;

    auto posX = pos.GetX();
    auto posY = pos.GetY();

    switch (type)
    {
    case TetrominoType::I: 
        cells = 
        {
            pos,
            Cell(posX + 1, posY),
            Cell(posX + 2, posY),
            Cell(posX + 3, posY)
        }; 
        break;

    case TetrominoType::S:
        cells =
        {
            pos, 
            Cell(posX + 1, posY),
            Cell(posX, posY + 1),
            Cell(posX - 1, posY + 1)
        };
        break;

    case TetrominoType::Z:
        cells =
        {
            pos,
            Cell(posX - 1, posY),
            Cell(posX, posY + 1),
            Cell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::O:
        cells =
        {
            pos,
            Cell(posX + 1, posY),
            Cell(posX, posY + 1),
            Cell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::T:
        cells =
        {
            pos,
            Cell(posX + 1, posY),
            Cell(posX + 2, posY),
            Cell(posX + 1, posY + 1)
        };
        break;

    case TetrominoType::L:
        cells =
        {
            pos,
            Cell(posX + 1, posY),
            Cell(posX + 2, posY),
            Cell(posX, posY + 1)
        };
        break;

    case TetrominoType::J:
        cells =
        {
            pos,
            Cell(posX + 1, posY),
            Cell(posX + 2, posY),
            Cell(posX + 2, posY + 1)
        };
        break;
    }
}

void Tetromino::FallDawn()
{
    for (auto& cell : cells)
    {
        cell.MoveY(cell.GetY() + 1);
    }
}
