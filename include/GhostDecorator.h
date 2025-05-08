#ifndef GHOST_DECORATOR_H
#define GHOST_DECORATOR_H
#include "Ghost.h"

class GhostDecorator : public Ghost {
public:
    GhostDecorator(std::unique_ptr<Ghost> ghost);
    void update(const Map& map, const PacMan& pacman) override;
    int getX() const override { return wrappedGhost->getX(); }
    int getY() const override { return wrappedGhost->getY(); }
    std::string getName() const override { return wrappedGhost->getName(); }
    std::string getStateName() const override { return wrappedGhost->getStateName(); }
protected:
    std::unique_ptr<Ghost> wrappedGhost;
};

class SpeedBoostDecorator : public GhostDecorator {
public:
    SpeedBoostDecorator(std::unique_ptr<Ghost> ghost);
    void update(const Map& map, const PacMan& pacman) override;
    bool isSpeedBoosted() const override { return true; }
};
#endif