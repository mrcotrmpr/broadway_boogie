#include "factories/museum_factory.hpp"

std::shared_ptr<Museum> MuseumFactory::createMuseum(int numRows, int numCols, std::vector<std::shared_ptr<NodeType>> nodeTypes, std::vector<std::shared_ptr<Node>> nodes)
{
    return std::make_shared<Museum>(numRows, numCols, nodeTypes, nodes);
}
