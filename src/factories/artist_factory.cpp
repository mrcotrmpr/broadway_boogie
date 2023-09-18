#include "factories/artist_factory.hpp"

std::shared_ptr<Artist> ArtistFactory::createArtist(float x, float y, float vx, float vy) {
    return std::make_shared<Artist>(x, y, vx, vy);
}
