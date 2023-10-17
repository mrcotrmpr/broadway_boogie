#include "presentation/commands/toggle_pathfinding_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void TogglePathfindingCommand::execute(std::shared_ptr<Game> game)
{
	game->breadthFirstSearch = !game->breadthFirstSearch;
}
