#include "PacMan.h"

PacMan::PacMan(int x, int y) : x(x), y(y), powerMode(false), powerDuration(0) {}

void PacMan::move(int dx, int dy, const Map& map) {
    int newX = x + dx;
    int newY = y + dy;
    if (!map.isWall(newX, newY)) {
        x = newX;
        y = newY;
    }
}

bool PacMan::eatPellet(Map& map) {
    char tile = map.getTile(x, y);
    if (tile == '.' || tile == '*') {
        map.setTile(x, y, ' ');
        if (tile == '*') {
            powerMode = true;
            powerDuration = 10;
        }
        return true;
    }
    return false;
}

void PacMan::updatePowerMode() {
    if (powerMode && powerDuration > 0) {
        powerDuration--;
        if (powerDuration == 0) {
            powerMode = false;
        }
    }
}

bool PacMan::hasPower() const {
    return powerMode;
}