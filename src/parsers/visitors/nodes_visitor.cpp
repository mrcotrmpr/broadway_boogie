#include "parsers/visitors/nodes_visitor.hpp"
#include <iostream>

void NodesVisitor::visit(std::shared_ptr<Museum> museum) {
    std::cout << "Visited <nodes> element." << std::endl;
}
