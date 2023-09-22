#include "parsers/visitors/node_visitor.hpp"
#include <iostream>

void NodeVisitor::visit(std::shared_ptr<Museum> museum) {
    std::cout << "Visited <node> element." << std::endl;
}
