#include "parsers/visitors/canvas_visitor.hpp"
#include <iostream>

void CanvasVisitor::visit(std::shared_ptr<Museum> museum) {
    std::cout << "Visited <canvas> element." << std::endl;
}
