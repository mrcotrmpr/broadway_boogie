#include "managers/pathfinding_manager.hpp"
#include <iostream>
#include "domain/node.hpp"
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <chrono>

void PathfindingManager::breadthFirstSearch(std::shared_ptr<Game> game)
{
    if (!game->pathFindingStart || !game->pathFindingEnd || !game->museum) {
        std::cerr << "Start, end, or museum not set for pathfinding." << std::endl;
        return;
    }

    game->museum->clearNodeVisitedTags();

    std::queue<std::shared_ptr<Node>> nodeQueue; // Store nodes that need to be visited, pop() them when being visited
    std::unordered_map<std::shared_ptr<Node>, int> steps; // Steps to reach each node, from the starting node

    nodeQueue.push(game->pathFindingStart);
    steps[game->pathFindingStart] = 0; // Steps to reach start, from start = 0

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
                // Mark the node as visited, add it to the queue to explore
                neighbor->visited = 'V';
                nodeQueue.push(neighbor);
                steps[neighbor] = steps[currentNode] + 1; // Neighbour is 1 step further than current node
            }
            // Found in the steps map, has already been visited
        }
    }

    // Backtrack the shortest path
    std::shared_ptr<Node> currentNode = game->pathFindingEnd;
    while (currentNode != game->pathFindingStart) {
        currentNode->visited = 'P';
        for (const auto& neighbor : currentNode->getNeighbors(game)) {
            // Neighbour found in the steps map & steps is one less than the current node
            if (steps.find(neighbor) != steps.end() && steps[neighbor] == steps[currentNode] - 1) {
                currentNode = neighbor;
                break;
            }
        }
    }
    game->pathFindingStart->visited = 'S';
}


void PathfindingManager::dijkstra(std::shared_ptr<Game> game)
{
    if (!game->pathFindingStart || !game->pathFindingEnd || !game->museum) {
        std::cerr << "Start, end, or museum not set for pathfinding." << std::endl;
        return;
    }

    game->museum->clearNodeVisitedTags();

    auto start = std::chrono::steady_clock::now();

    std::unordered_map<char, std::shared_ptr<NodeType>> nodeTypeMap;
    for (auto type : game->museum->nodeTypes) {
        nodeTypeMap[type->tag] = type;
    }

    // Create a map to store distances to nodes
    std::unordered_map<std::shared_ptr<Node>, int> distances;
    // Initialize distances to all nodes as infinity (so its marked unvisited)
    for (auto node : game->museum->nodes) {
        distances[node] = INT_MAX;
    }

    // Set the distance to the start node as 0
    distances[game->pathFindingStart] = 0;

    // Create a priority queue to store nodes with their distances
    std::priority_queue<
        std::pair<int, std::shared_ptr<Node>>, // Distance from starting node to current node
        std::vector<std::pair<int, std::shared_ptr<Node>>>, // Set correct container type
        std::greater<std::pair<int, std::shared_ptr<Node>>> // Prioritize nodes with smallest distances
    > priorityQueue;

    // Distance from start to start = 0
    priorityQueue.push({ 0, game->pathFindingStart });

    // Map to store the previous node for backtracking purposes
    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> previous;

    while (!priorityQueue.empty()) {
        auto current = priorityQueue.top().second;
        priorityQueue.pop();

        if (current == game->pathFindingEnd) {
            // Path has been found
            break;
        }

        for (const auto& neighbor : current->getNeighbors(game)) {
            neighbor->visited = 'V';

            // Calculate the distance from the start node to the current neighbor
            int distance = distances[current] + nodeTypeMap[neighbor->tag]->weight;

            if (distance < distances[neighbor]) {
                // Shorter path found
                distances[neighbor] = distance;
                previous[neighbor] = current;
                priorityQueue.push({ distance, neighbor });
            }
        }
    }

    // Backtrack the optimal path and set the nodes to 'P'
    auto currentNode = game->pathFindingEnd;
    while (currentNode != nullptr && currentNode != game->pathFindingStart) {
        currentNode->visited = 'P';
        currentNode = previous[currentNode];
    }

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken for dijkstra(): " << duration.count() << " miliseconds" << std::endl;

    game->pathFindingStart->visited = 'S';
}
