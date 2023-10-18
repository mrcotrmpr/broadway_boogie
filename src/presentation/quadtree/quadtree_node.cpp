#include "presentation/quadtree/quadtree_node.hpp"

QuadtreeNode::QuadtreeNode(int pLevel, float pX, float pY, float pWidth, float pHeight) : level(pLevel), x(pX), y(pY), width(pWidth), height(pHeight) {
    points = std::vector<std::shared_ptr<Artist>>();
    children = std::vector<std::shared_ptr<QuadtreeNode>>();
}

void QuadtreeNode::clear() {
    points.clear();
}

void QuadtreeNode::split() {
    float subWidth = width / 2;
    float subHeight = height / 2;
    float x = this->x;
    float y = this->y;

    points.clear();
}
