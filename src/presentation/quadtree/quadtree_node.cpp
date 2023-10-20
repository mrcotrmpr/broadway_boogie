#include "presentation/quadtree/quadtree_node.hpp"
#include "iostream"

QuadtreeNode::QuadtreeNode(int pLevel, float pX, float pY, float pWidth, float pHeight, float scaleX, float scaleY) : level(pLevel), x(pX), y(pY), width(pWidth), height(pHeight), scaleX(scaleX), scaleY(scaleY) {
    points = std::vector<std::shared_ptr<Artist>>();
    children = std::vector<std::shared_ptr<QuadtreeNode>>();
}

std::vector<std::shared_ptr<Artist>> QuadtreeNode::getPoints()
{
    return points;
}

void QuadtreeNode::insert(std::shared_ptr<Artist> artist) {
    if (children.empty()) {
        if (points.size() <= MAX_CAPACITY) {
            points.push_back(artist);
        }
        else {
            split();
            for (const auto& a : points) {
                // Add the point to each appropriate child node if it lies within its bounds
                for (const auto& child : children) {
                    if (child->contains(a)) {
                        child->points.push_back(a);
                    }
                }
            }
            points.clear();
        }
    }
    else {
        for (const auto& child : children) {
            if (child->contains(artist)) {
                child->insert(artist);
                break;
            }
        }
    }
}

bool QuadtreeNode::contains(const std::shared_ptr<Artist>& point) const {
    if (point == nullptr) {
        return true;
    }
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
            if (child->contains(point)) {
                child->points.push_back(point);
            }
        }
    }
    points.clear();
}

void QuadtreeNode::clear() {
    if (children.empty()) {
        points.clear();
    } else {
        for (const auto& child : children) {
            child->clear();
        }
    }
    children.clear();
}

void QuadtreeNode::update(std::vector<std::shared_ptr<Artist>> artists) {
    clear();
    for (const auto& a : artists) {
        insert(a);
    }
}
