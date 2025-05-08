#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Map.h"
#include "PacMan.h"
#include "Ghost.h"
#include <vector>
#include <memory>

class GameManager {
public:
    GameManager();
    void addGhost(std::unique_ptr<Ghost> ghost);
    void update(Map& map, PacMan& pacman); // Change to non-const Map&
    bool isGameOver() const;
    bool hasWon() const;
    int getScore() const { return score; }
    const std::vector<std::unique_ptr<Ghost>>& getGhosts() const { return ghosts; }
private:
    std::vector<std::unique_ptr<Ghost>> ghosts;
    int score;
    bool gameOver;
    bool won;
    int totalPellets;
    int pelletsEaten;
    void checkCollisions(PacMan& pacman);
    void countPellets(const Map& map);
};
#endif 