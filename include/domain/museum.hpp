#ifndef MUSEUM_HPP
#define MUSEUM_HPP

#include <vector>
#include "node.hpp"
#include "node_type.hpp"
#include "iostream"

class Museum {
public:
	Museum() = default;
	Museum(int numRows, int numCols);
	int numRows;
	int numCols;
	std::vector<std::shared_ptr<NodeType>> nodeTypes;
	std::vector<std::shared_ptr<Node>> nodes;
};

#endif // MUSEUM_HPP
