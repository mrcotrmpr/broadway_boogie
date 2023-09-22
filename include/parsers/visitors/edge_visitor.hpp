#ifndef EDGE_VISITOR_HPP
#define EDGE_VISITOR_HPP

#include "visitor.hpp"

class EdgeVisitor : public Visitor {
public:
    void visit(std::shared_ptr<Museum> museum) override;
};

#endif // EDGE_VISITOR_HPP
