#include "managers/pathfinding_manager.hpp"
#include <iostream>
#include "domain/node.hpp"
#include <queue>
#include <unordered_set>

void PathfindingManager::breadthFirstSearch(std::shared_ptr<Game> game)
{
    if (!game->pathFindingStart || !game->pathFindingEnd || !game->museum) {
        std::cerr << "Start, end, or museum not set for pathfinding." << std::endl;
        return;
    }

    std::queue<std::shared_ptr<Node>> nodeQueue;
    std::unordered_set<std::shared_ptr<Node>> visited;
    int steps = 0;

    nodeQueue.push(game->pathFindingStart);
    visited.insert(game->pathFindingStart);

    while (!nodeQueue.empty()) {
        std::shared_ptr<Node> currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode == game->pathFindingEnd) {
            // Path has been found
            std::cout << "Number of steps taken for breadthFirstSearch(): " << steps << std::endl;
            break;
        }

        // Traverse the neighboring nodes of the current node
        for (const auto& neighbor : currentNode->getNeighbors(game)) {
            if (visited.find(neighbor) == visited.end()) {
                // Mark the node as visited and add it to the queue for further exploration
                visited.insert(neighbor);
                nodeQueue.push(neighbor);
                steps++;
            }
        }
    }
}


void PathfindingManager::dijkstra(std::shared_ptr<Game> game)
{
}
