#ifndef CANVAS_VISITOR_HPP
#define CANVAS_VISITOR_HPP

#include "visitor.hpp"

class CanvasVisitor : public Visitor {
public:
    void visit(std::shared_ptr<Museum> museum) override;
};

#endif // CANVAS_VISITOR_HPP
