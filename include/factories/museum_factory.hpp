#ifndef MUSEUM_FACTORY_HPP
#define MUSEUM_FACTORY_HPP

#include "domain/museum.hpp"
#include <memory>

class MuseumFactory {
public:
    static std::shared_ptr<Museum> createMuseum(int numRows, int numCols, std::vector<std::shared_ptr<NodeType>> nodeTypes, std::vector<std::shared_ptr<Node>> nodes);
};

#endif // MUSEUM_FACTORY_HPP
