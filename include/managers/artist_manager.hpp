#ifndef ARTIST_MANAGER_HPP
#define ARTIST_MANAGER_HPP

#include <vector>
#include <memory>
#include "domain/artist.hpp"
#include "domain/museum.hpp"
#include <SDL.h>

class ArtistManager {
public:
    void renderArtists(SDL_Renderer* renderer, std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY);
    void moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists, bool artistsMoving);
    void detectCollisions(std::vector<std::shared_ptr<Artist>>& artists, std::shared_ptr<Museum> museum, float scaleX, float scaleY, bool artistsMoving);
    std::shared_ptr<Node> getNode(float x, float y, std::shared_ptr<Museum> museum, float scaleX, float scaleY);
};

#endif // ARTIST_MANAGER_HPP
