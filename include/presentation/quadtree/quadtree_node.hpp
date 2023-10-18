#ifndef QUADTREE_NODE_HPP
#define QUADTREE_NODE_HPP

#include <vector>
#include <memory>
#include "domain/artist.hpp"

class QuadtreeNode {
public:
    QuadtreeNode(int pLevel, float pX, float pY, float pWidth, float pHeight);
    void removePoint(std::shared_ptr<Artist> artist);
    void clear();
    void split();
    int level;
    float x, y, width, height;
    std::vector<std::shared_ptr<Artist>> points;
    std::vector<std::shared_ptr<QuadtreeNode>> children;
};

#endif // QUADTREE_NODE_HPP
