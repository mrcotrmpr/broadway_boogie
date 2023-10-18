#include "presentation/commands/load_documents_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void LoadDocumentsCommand::execute(std::shared_ptr<Game> game)
{
    if (game->atPresent) {
        if (!game->museum) {
            game->museum = museumManager->loadMuseum();
        }
        if (game->getArtists().empty()) {
            std::vector<std::shared_ptr<Artist>> loadedArtists = artistManager->loadArtists();
            for (const auto& artist : loadedArtists) {
                game->addArtist(artist);
            }
        }
    }
}
