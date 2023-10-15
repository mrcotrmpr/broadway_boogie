#include "presentation/commands/load_museum_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void LoadMuseumCommand::execute(std::shared_ptr<Game> game)
{
    if (game->atPresent) {
        if (!game->museum) {
            game->museum = manager->loadMuseum();
        }
    }
}
