#include "presentation/commands/load_artist_command.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void LoadArtistCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
    if (game->atPresent) {
        if (game->artists.empty()) {
            game->artists = artistManager->loadArtists();
        }
        else {
            game->artists.clear();
        }
    }
}
