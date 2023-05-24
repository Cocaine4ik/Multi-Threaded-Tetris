#pragma once
class Cell
{
private:
    int x;
    int y;
    
public:
    Cell() : x(0), y(0) {};
    Cell(int x, int y) { this->x = x, this->y = y; };

    int GetX() const { return x; }
    int GetY() const { return y; }

    void SetX(int value) { x = value; }
    void SetY(int value) { y = value; }

    void MoveX(int value) { x += value; }
    void MoveY(int value) { y += value; }

    void SetCoordinates(int x, int y) { this->x = x; this->y = y; }
};

