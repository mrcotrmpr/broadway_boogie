#include "presentation/quadtree/quadtree.hpp"

Quadtree::Quadtree(float pX, float pY, float pWidth, float pHeight, float scaleX, float scaleY) {
    root = std::make_shared<QuadtreeNode>(0, pX, pY, pWidth, pHeight, scaleX, scaleY);
}
