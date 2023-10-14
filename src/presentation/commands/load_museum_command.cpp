#include "presentation/commands/load_museum_command.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void LoadMuseumCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
    if (!game->museum) {
        game->museum = museumManager->loadMuseum();
    }
}
