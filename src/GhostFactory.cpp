#include "GhostFactory.h"
#include "GhostState.h"

class Blinky : public Ghost {
public:
    Blinky(int x, int y) : Ghost("Blinky", x, y) {
        setState(std::make_unique<ChaseState>());
    }
};

class Pinky : public Ghost {
public:
    Pinky(int x, int y) : Ghost("Pinky", x, y) {
        setState(std::make_unique<WanderState>());
    }
};

class Inky : public Ghost {
public:
    Inky(int x, int y) : Ghost("Inky", x, y) {
        setState(std::make_unique<WanderState>());
    }
};

class Clyde : public Ghost {
public:
    Clyde(int x, int y) : Ghost("Clyde", x, y) {
        setState(std::make_unique<WanderState>());
    }
};

std::unique_ptr<Ghost> BlinkyFactory::createGhost() const {
    return std::make_unique<Blinky>(3, 3);
}

std::unique_ptr<Ghost> PinkyFactory::createGhost() const {
    return std::make_unique<Pinky>(4, 3);
}

std::unique_ptr<Ghost> InkyFactory::createGhost() const {
    return std::make_unique<Inky>(3, 4);
}

std::unique_ptr<Ghost> ClydeFactory::createGhost() const {
    return std::make_unique<Clyde>(4, 4);
}