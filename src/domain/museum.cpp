#include "domain/museum.hpp"

Museum::Museum(int numRows, int numCols, std::vector<std::shared_ptr<NodeType>> nodeTypes, std::vector<std::shared_ptr<Node>> nodes)
    : numRows(numRows), numCols(numCols), nodeTypes(nodeTypes), nodes(nodes) {}
