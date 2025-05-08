#ifndef GAME_H
#define GAME_H
#include "GameManager.h"
#include "Map.h"
#include "PacMan.h"

class Game {
public:
    Game();
    void addGhost(std::unique_ptr<Ghost> ghost); // Delegasi ke GameManager
    void run();
private:
    Map map;
    PacMan pacman;
    GameManager manager;
};
#endif