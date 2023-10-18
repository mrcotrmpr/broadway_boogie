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

    std::queue<std::shared_ptr<Node>> nodeQueue;
    std::unordered_map<std::shared_ptr<Node>, int> steps; // Track steps for each node

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
            neighbor->visited = 'V';
            if (steps.find(neighbor) == steps.end()) {
                // Mark the node as visited, add it to the queue for further exploration, and update the steps
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
        std::pair<int, std::shared_ptr<Node>>, // Element type: pairs of integers and shared pointers to Node objects
        std::vector<std::pair<int, std::shared_ptr<Node>>>, // Container type: vector of pairs
        std::greater<std::pair<int, std::shared_ptr<Node>>> // Comparison function to order elements in the queue
    > priorityQueue;

    priorityQueue.push({ 0, game->pathFindingStart });

    // Map to store the previous node in the optimal path
    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> previous;

    while (!priorityQueue.empty()) {
        auto current = priorityQueue.top().second;
        priorityQueue.pop();

        // Stop if the current node is the target node
        if (current == game->pathFindingEnd) {
            break;
        }

        // Traverse the neighboring nodes of the current node
        for (const auto& neighbor : current->getNeighbors(game)) {
            neighbor->visited = 'V';
            // Calculate the distance from the start node to the neighbor
            int distance = distances[current] + nodeTypeMap[neighbor->tag]->weight;

            // If the new distance is smaller than the existing distance, update the distance and the previous node
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = current;
                priorityQueue.push({ distance, neighbor });
            }
        }

        // Backtrack the optimal path and set the nodes to 'P'
        auto currentNode = game->pathFindingEnd;
        while (currentNode != nullptr && currentNode != game->pathFindingStart) {
            currentNode->visited = 'P';
            currentNode = previous[currentNode];
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken for dijkstra(): " << duration.count() << " miliseconds" << std::endl;

    game->pathFindingStart->visited = 'S';
}
