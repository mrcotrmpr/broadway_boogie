#include "presentation/commands/toggle_path_collision_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void TogglePathCollisionCommand::execute(std::shared_ptr<Game> game)
{
	game->pathCollision = !game->pathCollision;
}
