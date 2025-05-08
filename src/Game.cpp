#include "Game.h"
#include "Input.h"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game() : pacman(2, 2) {
    Input::init();
}

void Game::addGhost(std::unique_ptr<Ghost> ghost) {
    manager.addGhost(std::move(ghost));
}

void Game::run() {
    bool running = true;
    while (running && !manager.isGameOver()) {
        system("cls");
        switch (Input::getKey()) {
            case Input::UP: pacman.move(0, -1, map); break;
            case Input::DOWN: pacman.move(0, 1, map); break;
            case Input::LEFT: pacman.move(-1, 0, map); break;
            case Input::RIGHT: pacman.move(1, 0, map); break;
            case Input::QUIT: running = false; break;
            default: break;
        }
        manager.update(map, pacman);
        map.render(pacman, manager.getGhosts()); // Use getGhosts()
        std::cout << "Pac-Man at (" << pacman.getX() << "," << pacman.getY() << ")";
        if (pacman.hasPower()) std::cout << " [POWER MODE]";
        std::cout << "\nScore: " << manager.getScore() << std::endl;
        for (const auto& ghost : manager.getGhosts()) { // Use getGhosts()
            std::cout << ghost->getName() << " at (" << ghost->getX() << "," 
                      << ghost->getY() << ") [" << ghost->getStateName() << "]" 
                      << (ghost->isSpeedBoosted() ? " [SPEED BOOST]" : "") << std::endl;
        }
        if (manager.hasWon()) {
            std::cout << "You Win! All pellets eaten!" << std::endl;
        } else if (manager.isGameOver()) {
            std::cout << "Game Over! Pac-Man was caught!" << std::endl;
        }
        std::cout << "Use arrow keys to move, 'q' to quit." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    Input::cleanup();
}