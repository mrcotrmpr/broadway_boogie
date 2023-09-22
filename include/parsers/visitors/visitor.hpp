#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "iostream"

class Museum;

class Visitor {
public:
    virtual void visit(std::shared_ptr<Museum> museum) = 0;
};

#endif // VISITOR_HPP
