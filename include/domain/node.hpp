#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "edge.hpp"
#include "iostream"
#include "states/node_state.hpp"

class Node {
public:
    Node() = default;
    Node(char tag, int x, int y);
    char tag;
    int x;
    int y;
    int interactions = 0;
    std::vector<std::shared_ptr<Edge>> edges;
    std::shared_ptr<NodeState> state;
};

#endif // NODE_HPP
