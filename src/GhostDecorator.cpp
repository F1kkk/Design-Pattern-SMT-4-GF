#include "GhostDecorator.h"
#include "GhostState.h" // Added for WanderState

GhostDecorator::GhostDecorator(std::unique_ptr<Ghost> ghost) 
    : Ghost("Decorator", ghost->getX(), ghost->getY()), wrappedGhost(std::move(ghost)) {
    // Initialize state to match wrapped ghost
    if (wrappedGhost->getStateName() != "None") {
        setState(std::make_unique<WanderState>()); // Default state
    }
}

void GhostDecorator::update(const Map& map, const PacMan& pacman) {
    wrappedGhost->update(map, pacman);
}

SpeedBoostDecorator::SpeedBoostDecorator(std::unique_ptr<Ghost> ghost) 
    : GhostDecorator(std::move(ghost)) {}

void SpeedBoostDecorator::update(const Map& map, const PacMan& pacman) {
    // Simulate speed boost by moving twice
    wrappedGhost->update(map, pacman);
    wrappedGhost->update(map, pacman);
}