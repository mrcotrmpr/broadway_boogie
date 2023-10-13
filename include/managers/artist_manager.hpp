#ifndef ARTIST_MANAGER_HPP
#define ARTIST_MANAGER_HPP

#include <vector>
#include <memory>
#include "domain/artist.hpp"
#include "presentation/game.hpp"
#include "domain/museum.hpp"
#include <SDL.h>

class ArtistManager {
public:
    void renderArtists(SDL_Renderer* renderer, std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY);
    void moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists, bool artistsMoving);
    void detectCollisions(std::shared_ptr<Game> game, float scaleX, float scaleY, bool artistsMoving);
};

#endif // ARTIST_MANAGER_HPP
