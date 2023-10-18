#ifndef ARTIST_MANAGER_HPP
#define ARTIST_MANAGER_HPP

#include <vector>
#include <memory>
#include "domain/artist.hpp"
#include "presentation/game.hpp"
#include "domain/museum.hpp"
#include "readers/csv_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/csv_parser.hpp"
#include <SDL.h>

class ArtistManager {
public:
    std::vector<std::shared_ptr<Artist>> loadArtists();
    void renderArtists(SDL_Renderer* renderer, std::vector<std::shared_ptr<Artist>>& artists, std::shared_ptr<Game> game);
    void moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists, bool artistsMoving);
    void detectCollisions(std::shared_ptr<Game> game, float scaleX, float scaleY, bool artistsMoving);
    CSVReader csvReader;
    WebReader webReader;
    CSVParser csvParser;
};

#endif // ARTIST_MANAGER_HPP
