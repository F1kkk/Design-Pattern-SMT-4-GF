#include "Game.h"
#include "GhostFactory.h"

int main() {
    Game game;
    game.addGhost(BlinkyFactory().createGhost());
    game.addGhost(PinkyFactory().createGhost());
    game.addGhost(InkyFactory().createGhost());
    game.addGhost(ClydeFactory().createGhost());
    game.run();
    return 0;
}