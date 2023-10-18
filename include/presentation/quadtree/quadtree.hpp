#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <vector>
#include <memory>
#include "quadtree_node.hpp"

class Quadtree {
public:
    Quadtree(float pX, float pY, float pWidth, float pHeight, float scaleX, float scaleY);
    std::shared_ptr<QuadtreeNode> root;
};

#endif // QUADTREE_HPP
