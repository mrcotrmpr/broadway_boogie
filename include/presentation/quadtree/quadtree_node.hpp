#ifndef QUADTREE_NODE_HPP
#define QUADTREE_NODE_HPP

#include <vector>
#include <memory>
#include "domain/artist.hpp"

class QuadtreeNode {
public:
    QuadtreeNode(int pLevel, float pX, float pY, float pWidth, float pHeight, float scaleX, float scaleY);
    void insert(std::shared_ptr<Artist> artist);
    void removePoint(std::shared_ptr<Artist> artist);
    bool contains(const std::shared_ptr<Artist>& point) const;
    void split();
    int level;
    float x, y, width, height, scaleX, scaleY;
    const int MAX_CAPACITY = 4;
    std::vector<std::shared_ptr<QuadtreeNode>> children;
private:
    std::vector<std::shared_ptr<Artist>> points;
};

#endif // QUADTREE_NODE_HPP
