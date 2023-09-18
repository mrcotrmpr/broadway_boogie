#ifndef ARTIST_FACTORY_HPP
#define ARTIST_FACTORY_HPP

#include "domain/artist.hpp"
#include <memory>

class ArtistFactory {
public:
    static std::shared_ptr<Artist> createArtist(float x, float y, float vx, float vy);
};

#endif // ARTIST_FACTORY_HPP
