#include "managers/pathfinding_manager.hpp"
#include <iostream>
#include "domain/node.hpp"
#include <queue>
#include <unordered_set>
#include <unordered_map>

void PathfindingManager::breadthFirstSearch(std::shared_ptr<Game> game)
{
    if (!game->pathFindingStart || !game->pathFindingEnd || !game->museum) {
        std::cerr << "Start, end, or museum not set for pathfinding." << std::endl;
        return;
    }

    game->museum->clearNodeVisitedTags();

    std::queue<std::shared_ptr<Node>> nodeQueue;
    std::unordered_map<std::shared_ptr<Node>, int> steps; // Track steps for each node

    game->pathFindingStart->visited = 'S';
    nodeQueue.push(game->pathFindingStart);
    steps[game->pathFindingStart] = 0;

    while (!nodeQueue.empty()) {
        std::shared_ptr<Node> currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode == game->pathFindingEnd) {
            // Path has been found
            std::cout << "Number of steps taken for breadthFirstSearch(): " << steps[currentNode] << std::endl;
            break;
        }

        // Traverse the neighboring nodes of the current node
        for (const auto& neighbor : currentNode->getNeighbors(game)) {
            if (steps.find(neighbor) == steps.end()) {
                // Mark the node as visited, add it to the queue for further exploration, and update the steps
                neighbor->visited = 'V';
                steps[neighbor] = steps[currentNode] + 1;
                nodeQueue.push(neighbor);
            }
        }
    }

    // Mark the nodes in the shortest path
    std::shared_ptr<Node> currentNode = game->pathFindingEnd;
    while (currentNode != game->pathFindingStart) {
        currentNode->visited = 'P';
        for (const auto& neighbor : currentNode->getNeighbors(game)) {
            if (steps.find(neighbor) != steps.end() && steps[neighbor] == steps[currentNode] - 1) {
                currentNode = neighbor;
                break;
            }
        }
    }
}


void PathfindingManager::dijkstra(std::shared_ptr<Game> game)
{
}
