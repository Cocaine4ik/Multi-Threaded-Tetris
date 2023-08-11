#pragma once
#include <thread>
#include <memory>
#include "Board.h"
#include "Tetromino.h"
#include <condition_variable>

class Game
{
private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Tetromino> currentTetromino;
    int score;
    bool isRunning;

    std::thread renderThread;
    std::thread inputThread;
    std::thread scoreThread;

    std::condition_variable scoreUpdateSignal;
    std::mutex scoreMutex;

public:
    Game();

    void StartGame();
    void PauseGame();
    void ExitGame();
    void HandleInput();
    void UpdateScore();
    void Render();

    void SpawnTetromino();

};

