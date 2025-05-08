#include "Map.h"
#include "PacMan.h" // Added for PacMan definition
#include "Ghost.h"  // Added for Ghost definition
#include <iostream>

Map::Map() {
    grid = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '.', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '*', '#'},
        {'#', '.', '#', '#', '.', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
}

bool Map::isWall(int x, int y) const {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return true;
    return grid[y][x] == '#';
}

char Map::getTile(int x, int y) const {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return '#';
    return grid[y][x];
}

void Map::setTile(int x, int y, char tile) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        grid[y][x] = tile;
    }
}

void Map::render(const PacMan& pacman, const std::vector<std::unique_ptr<Ghost>>& ghosts) const {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            char displayChar = grid[y][x];
            if (x == pacman.getX() && y == pacman.getY()) {
                displayChar = '<';
            }
            for (const auto& ghost : ghosts) {
                if (x == ghost->getX() && y == ghost->getY()) {
                    displayChar = ghost->getName()[0];
                }
            }
            std::cout << displayChar << " ";
        }
        std::cout << std::endl;
    }
}