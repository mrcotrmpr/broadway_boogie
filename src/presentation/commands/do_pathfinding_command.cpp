#include "presentation/commands/do_pathfinding_command.hpp"
#include "presentation/game.hpp"

void DoPathFindingCommand::execute(std::shared_ptr<Game> game)
{
	manager->breadthFirstSearch(game);
}
