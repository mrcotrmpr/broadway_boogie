#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "memory"

class Artist : public std::enable_shared_from_this<Artist> {
public:
    Artist(float x, float y, float vx, float vy);
    float x;
    float y;
    float vx;
    float vy;
};

#endif // ARTIST_HPP
