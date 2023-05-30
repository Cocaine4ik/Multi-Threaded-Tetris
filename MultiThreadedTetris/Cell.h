#pragma once
class Cell
{
private:
    int x;
    int y;
    char chr;
    
public:
    Cell() : x(0), y(0), chr(' ') {};
    Cell(int x, int y, char chr = ' ') { this->x = x, this->y = y, this->chr = chr; };

    int GetX() const { return x; }
    int GetY() const { return y; }
    char GetChr() const { return chr; }

    void SetX(int value) { x = value; }
    void SetY(int value) { y = value; }
    void SetChr(char value) { chr = value; }

    void MoveX(int value) { x += value; }
    void MoveY(int value) { y += value; }

    void SetCoordinates(int x, int y) { this->x = x; this->y = y; }
};

