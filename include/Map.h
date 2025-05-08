#ifndef MAP_H
#define MAP_H
#include <vector>
#include <memory> // For std::unique_ptr

class PacMan; // Forward declaration
class Ghost;  // Forward declaration

class Map {
public:
    Map();
    bool isWall(int x, int y) const;
    char getTile(int x, int y) const;
    void setTile(int x, int y, char tile);
    void render(const PacMan& pacman, const std::vector<std::unique_ptr<Ghost>>& ghosts) const;
private:
    static const int WIDTH = 10;
    static const int HEIGHT = 10;
    std::vector<std::vector<char>> grid;
};
#endif