#include "domain/node.hpp"
#include "presentation/game.hpp"

Node::Node(char tag, int x, int y)
    : tag(tag), x(x), y(y) {}

std::vector<std::shared_ptr<Node>> Node::getNeighbors(std::shared_ptr<Game> game) {
    std::vector<std::shared_ptr<Node>> neighbors;
    for (const auto& otherNode : game->museum->nodes) {
        if (otherNode != shared_from_this()) {
            if (otherNode->x == x && (otherNode->y == y - 1 || otherNode->y == y + 1)) {
                // Above or below
                neighbors.push_back(otherNode);
            }
            else if (otherNode->y == y && (otherNode->x == x - 1 || otherNode->x == x + 1)) {
                // Left or right
                neighbors.push_back(otherNode);
            }
        }
    }
    return neighbors;
}
