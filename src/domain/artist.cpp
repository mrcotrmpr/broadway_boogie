#include "domain/artist.hpp"

Artist::Artist(float x, float y, float vx, float vy)
    : x(x), y(y), vx(vx), vy(vy) {}

float Artist::getX() const {
    return x;
}

float Artist::getY() const {
    return y;
}

float Artist::getVX() const {
    return vx;
}

float Artist::getVY() const {
    return vy;
}
