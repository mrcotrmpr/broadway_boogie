#include "presentation/commands/toggle_collision_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleCollisionCommand::execute(std::shared_ptr<Game> game)
{
	if (game->atPresent) {
		game->checkCollisionsNaive = !game->checkCollisionsNaive;
	}
}
