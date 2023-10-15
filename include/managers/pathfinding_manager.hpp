#ifndef PATHFINDING_MANAGER_HPP
#define PATHFINDING_MANAGER_HPP

#include <vector>
#include <memory>
#include "presentation/game.hpp"

class PathfindingManager {
public:
    void breadthFirstSearch(std::shared_ptr<Game> game);
    void dijkstra(std::shared_ptr<Game> game);
};

#endif // PATHFINDING_MANAGER_HPP
