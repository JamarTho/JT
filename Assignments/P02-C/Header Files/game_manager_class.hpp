#pragma once
#include <string>
#include "logger_class.hpp"
#include "player_class.hpp"
#include "dice_class.hpp"

class GameManager {
public:
    GameManager(const std::string& player1Name, const std::string& player2Name);
    void start();
    void playTurn(Player& currentPlayer);
    void switchTurns();
    void displayScores();
    void printGameStatus();

private:
    Player player1;
    Player player2;
    DiceViz dice;
    bool isGameOver;
    bool isPlayer1Turn;
    int turnCount;
    void logGameStatus();
};
