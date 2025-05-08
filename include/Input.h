#ifndef INPUT_H
#define INPUT_H

#include <utility>

class Input {
public:
    enum Key { NONE, UP, DOWN, LEFT, RIGHT, QUIT };
    static Key getKey();
    static void init();
    static void cleanup();
};

#endif