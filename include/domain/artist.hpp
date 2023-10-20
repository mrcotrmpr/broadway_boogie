#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "memory"

class Node;

class Artist : public std::enable_shared_from_this<Artist> {
public:
    Artist() = default;
    Artist(float x, float y, float vx, float vy);
    float x;
    float y;
    float vx;
    float vy;
    int direction = rand() % 4;
    char colorTag = 'B';
    std::shared_ptr<Node> lastNode = nullptr;
    bool leftFirstNode = false;
};

#endif // ARTIST_HPP
