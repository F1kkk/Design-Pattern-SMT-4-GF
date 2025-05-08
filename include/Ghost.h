#ifndef GHOST_H
#define GHOST_H
#include "Map.h"
#include "PacMan.h"
#include <string>
#include <memory>

class GhostState; // Forward declaration

class Ghost {
public:
    Ghost(const std::string& name, int x, int y);
    virtual ~Ghost(); // Declare, don’t define inline
    virtual void update(const Map& map, const PacMan& pacman);
    void setState(std::unique_ptr<GhostState> newState); // Declare only
    void setFrightened(); // Declare only
    virtual int getX() const { return x; }
    virtual int getY() const { return y; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
    virtual std::string getName() const { return name; }
    virtual std::string getStateName() const; // Declare only
    virtual bool isSpeedBoosted() const { return false; }
protected:
    std::string name;
    int x, y;
    std::unique_ptr<GhostState> state;
};
#endif