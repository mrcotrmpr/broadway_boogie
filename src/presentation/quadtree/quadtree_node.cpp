#include "presentation/quadtree/quadtree_node.hpp"
#include "iostream"

QuadtreeNode::QuadtreeNode(int pLevel, float pX, float pY, float pWidth, float pHeight, float scaleX, float scaleY) : level(pLevel), x(pX), y(pY), width(pWidth), height(pHeight), scaleX(scaleX), scaleY(scaleY) {
    points = std::vector<std::shared_ptr<Artist>>();
    children = std::vector<std::shared_ptr<QuadtreeNode>>();
}

std::vector<std::shared_ptr<Artist>> QuadtreeNode::getPoints() {
    return this->points;
}

void QuadtreeNode::removePoint(std::shared_ptr<Artist> artist) {
    auto it = std::find(points.begin(), points.end(), artist);
    if (it != points.end()) {
        points.erase(it);
    }
    else {
        for (const auto& child : children) {
            child->removePoint(artist);
        }
    }
}

void QuadtreeNode::insert(std::shared_ptr<Artist> artist) {
    if (!containsPoint(artist)) {
        return;
    }

    if (!children.empty()) {
        for (const auto& child : children) {
            child->insert(artist);
        }
    }
    else {
        points.push_back(artist);
        if (points.size() > MAX_CAPACITY) {
            split();
        }
    }
}

void QuadtreeNode::unsplit() {
    if (!children.empty()) {
        for (const auto& child : children) {
            child->unsplit();
            for (const auto& point : child->points) {
                points.push_back(point);
            }
        }
        children.clear();
    }
}

void QuadtreeNode::clear() {
    points.clear();
}

bool QuadtreeNode::containsPoint(const std::shared_ptr<Artist>& point) const {
    return (point->x * scaleX >= x && point->x * scaleX <= (x + width) && point->y * scaleY >= y && point->y * scaleY <= (y + height));
}

void QuadtreeNode::split() {
    float subWidth = width / 2;
    float subHeight = height / 2;
    float x = this->x;
    float y = this->y;

    children.emplace_back(std::make_shared<QuadtreeNode>(level + 1, x, y, subWidth, subHeight, scaleX, scaleY));
    children.emplace_back(std::make_shared<QuadtreeNode>(level + 1, x + subWidth, y, subWidth, subHeight, scaleX, scaleY));
    children.emplace_back(std::make_shared<QuadtreeNode>(level + 1, x, y + subHeight, subWidth, subHeight, scaleX, scaleY));
    children.emplace_back(std::make_shared<QuadtreeNode>(level + 1, x + subWidth, y + subHeight, subWidth, subHeight, scaleX, scaleY));

    for (const auto& point : points) {
        for (const auto& child : children) {
            if (child->containsPoint(point)) {
                child->points.push_back(point);
            }
        }
    }
    points.clear();
}
