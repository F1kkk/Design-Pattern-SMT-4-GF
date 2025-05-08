#include "GameManager.h"
#include "GhostDecorator.h"
#include "GhostState.h" // Added for ReturnToBaseState

GameManager::GameManager() 
    : score(0), gameOver(false), won(false), totalPellets(0), pelletsEaten(0) {}

void GameManager::addGhost(std::unique_ptr<Ghost> ghost) {
    ghosts.push_back(std::move(ghost));
}

void GameManager::update(Map& map, PacMan& pacman) { // Change to non-const Map&
    if (gameOver || won) return;

    // Hitung pellet awal jika belum dilakukan
    if (totalPellets == 0) {
        countPellets(map);
    }

    // Update Pac-Man
    pacman.updatePowerMode();
    if (pacman.eatPellet(map)) {
        char tile = map.getTile(pacman.getX(), pacman.getY());
        if (tile == '.') {
            score += 10;
            pelletsEaten++;
        } else if (tile == '*') {
            score += 50;
            pelletsEaten++;
            for (auto& ghost : ghosts) {
                ghost = std::make_unique<SpeedBoostDecorator>(std::move(ghost));
                ghost->setFrightened();
            }
        }
    }

    // Update ghosts
    for (auto& ghost : ghosts) {
        ghost->update(map, pacman);
    }

    // Cek tabrakan dan kondisi menang/kalah
    checkCollisions(pacman);
    if (pelletsEaten == totalPellets) {
        won = true;
        gameOver = true;
    }
}

bool GameManager::isGameOver() const {
    return gameOver;
}

bool GameManager::hasWon() const {
    return won;
}

void GameManager::checkCollisions(PacMan& pacman) {
    for (const auto& ghost : ghosts) {
        if (pacman.getX() == ghost->getX() && pacman.getY() == ghost->getY()) {
            if (pacman.hasPower()) {
                ghost->setPosition(5, 5); // Kembali ke base
                ghost->setState(std::make_unique<ReturnToBaseState>());
                score += 200; // Bonus makan ghost
            } else {
                gameOver = true; // Kalah jika tidak dalam power mode
            }
        }
    }
}

void GameManager::countPellets(const Map& map) {
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            char tile = map.getTile(x, y);
            if (tile == '.' || tile == '*') {
                totalPellets++;
            }
        }
    }
}