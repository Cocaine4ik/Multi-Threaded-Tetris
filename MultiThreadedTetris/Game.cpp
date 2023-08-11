#include "Game.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <memory>
#include <iostream>
#include "Board.h"
#include "Tetromino.h"

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
    while (isRunning)
    {
        if (GetAsyncKeyState(VK_SPACE))
        {
            currentTetromino->Rotate(board.get());
        }

        else if (GetAsyncKeyState(VK_ESCAPE))
        {

        }

        else if (GetAsyncKeyState(VK_A)) 
        {
            currentTetromino->Move(board.get(), -1, 0);
        }

        else if (GetAsyncKeyState(VK_D))
        {
            currentTetromino->Move(board.get(), 1, 0);
        }

        else if (GetAsyncKeyState(VK_S))
        {
            currentTetromino->Move(board.get(), 0, 1);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    


}

void Game::UpdateScore()
{
    std::unique_lock<std::mutex> lock(scoreMutex);

    while (isRunning)
    {
        scoreUpdateSignal.wait(lock);

        std::cout << std::endl;
        std::cout << "Score: " << score;
        std::cout << std::endl;
    }
}

void Game::Render()

{    
    while (isRunning)
    {
        SpawnTetromino();
        currentTetromino->Move(board.get(), 0, 1);

        board->Draw();

        scoreUpdateSignal.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("cls");
    }
}

void Game::SpawnTetromino()
{
    if (currentTetromino && !currentTetromino->IsBuilt()) return;
    
    currentTetromino = board->SpawnTetromino();
}
