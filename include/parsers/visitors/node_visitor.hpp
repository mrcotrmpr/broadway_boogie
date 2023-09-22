#ifndef NODE_VISITOR_HPP
#define NODE_VISITOR_HPP

#include "visitor.hpp"

class NodeVisitor : public Visitor {
public:
    void visit(std::shared_ptr<Museum> museum) override;
};

#endif // NODE_VISITOR_HPP
