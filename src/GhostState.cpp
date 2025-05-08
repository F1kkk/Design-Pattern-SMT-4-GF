#include "GhostState.h"
#include "Ghost.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void ChaseState::move(Ghost& ghost, const Map& map, const PacMan& pacman) {
    int gx = ghost.getX();
    int gy = ghost.getY();
    int px = pacman.getX();
    int py = pacman.getY();
    int dx = px > gx ? 1 : (px < gx ? -1 : 0);
    int dy = py > gy ? 1 : (py < gy ? -1 : 0);
    if (!map.isWall(gx + dx, gy)) {
        ghost.setPosition(gx + dx, gy);
    } else if (!map.isWall(gx, gy + dy)) {
        ghost.setPosition(gx, gy + dy);
    }
}

void WanderState::move(Ghost& ghost, const Map& map, const PacMan& pacman) {
    int gx = ghost.getX();
    int gy = ghost.getY();
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int choice = std::rand() % 4;
    int dx = directions[choice][0];
    int dy = directions[choice][1];
    if (!map.isWall(gx + dx, gy + dy)) {
        ghost.setPosition(gx + dx, gy + dy);
    }
}

void FrightenedState::move(Ghost& ghost, const Map& map, const PacMan& pacman) {
    int gx = ghost.getX();
    int gy = ghost.getY();
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int choice = std::rand() % 4;
    int dx = directions[choice][0];
    int dy = directions[choice][1];
    if (!map.isWall(gx + dx, gy + dy)) {
        ghost.setPosition(gx + dx, gy + dy);
    }
}

void ReturnToBaseState::move(Ghost& ghost, const Map& map, const PacMan& pacman) {
    int gx = ghost.getX();
    int gy = ghost.getY();
    int baseX = 5, baseY = 5;
    int dx = baseX > gx ? 1 : (baseX < gx ? -1 : 0);
    int dy = baseY > gy ? 1 : (baseY < gy ? -1 : 0);
    if (!map.isWall(gx + dx, gy)) {
        ghost.setPosition(gx + dx, gy);
    } else if (!map.isWall(gx, gy + dy)) {
        ghost.setPosition(gx, gy + dy);
    }
    if (gx == baseX && gy == baseY) {
        ghost.setState(std::make_unique<WanderState>());
    }
}