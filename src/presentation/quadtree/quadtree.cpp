#include "presentation/quadtree/quadtree.hpp"

Quadtree::Quadtree(float pX, float pY, float pWidth, float pHeight) {
    // Initialize the root node with the provided parameters
    root = std::make_shared<QuadtreeNode>(0, pX, pY, pWidth, pHeight);
}
