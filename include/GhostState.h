#ifndef GHOST_STATE_H
#define GHOST_STATE_H

#include "Map.h"
#include "PacMan.h"
#include <string>
#include <memory>

class Ghost; // Forward declaration

class GhostState {
public:
    virtual ~GhostState() = default;
    virtual void move(Ghost& ghost, const Map& map, const PacMan& pacman) = 0;
    virtual std::string getName() const = 0;
};

class ChaseState : public GhostState {
public:
    void move(Ghost& ghost, const Map& map, const PacMan& pacman) override;
    std::string getName() const override { return "Chase"; }
};

class WanderState : public GhostState {
public:
    void move(Ghost& ghost, const Map& map, const PacMan& pacman) override;
    std::string getName() const override { return "Wander"; }
};

class FrightenedState : public GhostState {
public:
    void move(Ghost& ghost, const Map& map, const PacMan& pacman) override;
    std::string getName() const override { return "Frightened"; }
};

class ReturnToBaseState : public GhostState {
public:
    void move(Ghost& ghost, const Map& map, const PacMan& pacman) override;
    std::string getName() const override { return "ReturnToBase"; }
};

#endif