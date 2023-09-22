#include "parsers/visitors/edge_visitor.hpp"
#include <iostream>

void EdgeVisitor::visit(std::shared_ptr<Museum> museum) {
    std::cout << "Visited <edge> element." << std::endl;
}
