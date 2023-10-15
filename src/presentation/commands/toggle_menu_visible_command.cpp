#include "presentation/commands/toggle_menu_visible_command.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleMenuVisibleCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
	if (game->atPresent) {
		game->menuVisible = !game->menuVisible;
	}
}
