#ifndef NODES_VISITOR_HPP
#define NODES_VISITOR_HPP

#include "visitor.hpp"

class NodesVisitor : public Visitor {
public:
    void visit(std::shared_ptr<Museum> museum) override;
};

#endif // NODES_VISITOR_HPP
