#ifndef GHOST_FACTORY_H
#define GHOST_FACTORY_H

#include "Ghost.h"
#include <memory>
#include <string>

class GhostFactory {
public:
    virtual ~GhostFactory() = default;
    virtual std::unique_ptr<Ghost> createGhost() const = 0;
};

class BlinkyFactory : public GhostFactory {
public:
    std::unique_ptr<Ghost> createGhost() const override;
};

class PinkyFactory : public GhostFactory {
public:
    std::unique_ptr<Ghost> createGhost() const override;
};

class InkyFactory : public GhostFactory {
public:
    std::unique_ptr<Ghost> createGhost() const override;
};

class ClydeFactory : public GhostFactory {
public:
    std::unique_ptr<Ghost> createGhost() const override;
};

#endif