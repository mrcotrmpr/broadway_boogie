#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "edge.hpp"
#include "iostream"
#include "memory"
#include "states/node_state.hpp"

class Game;

class Node : public std::enable_shared_from_this<Node> {
public:
    Node() = default;
    Node(char tag, int x, int y);
    char tag;
    char visited = ' ';
    int x;
    int y;
    int interactions = 0;
    std::vector<std::shared_ptr<Edge>> edges;
    std::shared_ptr<NodeState> state;
    std::vector<std::shared_ptr<Node>> getNeighbors(std::shared_ptr<Game> game);
};

#endif // NODE_HPP
