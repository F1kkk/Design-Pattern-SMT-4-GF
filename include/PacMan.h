#ifndef PACMAN_H
#define PACMAN_H
#include "Map.h"

class PacMan {
public:
    PacMan(int x, int y);
    void move(int dx, int dy, const Map& map);
    bool eatPellet(Map& map);
    void updatePowerMode();
    bool hasPower() const;
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x, y;
    bool powerMode;
    int powerDuration;
};
#endif