#include "Ghost.h"
#include "GhostState.h"

Ghost::Ghost(const std::string& name, int x, int y) 
    : name(name), x(x), y(y), state(std::make_unique<WanderState>()) {}

Ghost::~Ghost() {
    // unique_ptr automatically deletes state; GhostState.h provides the definition
}

void Ghost::update(const Map& map, const PacMan& pacman) {
    if (state) {
        state->move(*this, map, pacman);
    }
}

void Ghost::setState(std::unique_ptr<GhostState> newState) {
    state = std::move(newState);
}

void Ghost::setFrightened() {
    setState(std::make_unique<FrightenedState>());
}

std::string Ghost::getStateName() const {
    return state ? state->getName() : "None";
}