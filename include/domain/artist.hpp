#ifndef ARTIST_HPP
#define ARTIST_HPP

class Artist {
public:
    Artist(float x, float y, float vx, float vy);

    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;
    [[nodiscard]] float getVX() const;
    [[nodiscard]] float getVY() const;

private:
    float x;
    float y;
    float vx;
    float vy;
};

#endif // ARTIST_HPP
