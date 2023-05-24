#include <iostream>
#include "Game.h"

/**
* 1. GamMode головний клас який взаємодіє з іншими класами
* має в собі 3 потоки, які відпідають за рендер ігрового поля
* за інпут, і за геймплей
* 2.
*/

int main()
{
    Game game;
    game.StartGame();

    // game.StartGame();

    /*
    while (true)
    {
        tetromino.FallDawn();
        
        board.Draw();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }*/
}
