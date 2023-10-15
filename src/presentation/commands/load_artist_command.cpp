#include "presentation/commands/load_artist_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void LoadArtistCommand::execute(std::shared_ptr<Game> game)
{
    if (game->atPresent) {
        if (game->artists.empty()) {
            game->artists = manager->loadArtists();
        }
        else {
            game->artists.clear();
        }
    }
}
