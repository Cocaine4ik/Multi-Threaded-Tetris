#include "Game.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <memory>
#include "Board.h"

#define SPEED_DEFAULT 1.0
#define SPEED_MOD 1.0

#define VK_A 0x41
#define VK_D 0x44
#define VK_S 0x53

Game::Game()
{
    score = 0;
    isRunning = false;
}

void Game::StartGame()
{
    board = std::make_unique<Board>();
    currentTetromino = (board->SpawnTetromino(TetrominoType::I));

    isRunning = true;

    renderThread = std::thread(&Game::Render, this);
    inputThread = std::thread(&Game::HandleInput, this);
    scoreThread = std::thread(&Game::UpdateScore, this);

    renderThread.join();
    inputThread.join();
    scoreThread.join();
}

void Game::PauseGame()
{
}

void Game::ExitGame()
{
}

void Game::HandleInput()
{
    if (GetAsyncKeyState(VK_SPACE));
    else if (GetAsyncKeyState(VK_ESCAPE));
    else if (GetAsyncKeyState(VK_A));
    else if (GetAsyncKeyState(VK_D));
    else if (GetAsyncKeyState(VK_S));
}

void Game::UpdateScore()
{
}

void Game::Render()

{
    currentTetromino->FallDawn(board.get());
    board->Draw();
    /*
    while (true)
    {



        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }*/
}
