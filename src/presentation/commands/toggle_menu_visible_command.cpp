#include "presentation/commands/toggle_menu_visible_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleMenuVisibleCommand::execute(std::shared_ptr<Game> game)
{
	if (game->atPresent) {
		game->menuVisible = !game->menuVisible;
	}
}
