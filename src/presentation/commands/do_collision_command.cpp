#include "presentation/commands/do_collision_command.hpp"
#include "presentation/game.hpp"

void DoCollisionCommand::execute(std::shared_ptr<Game> game)
{
	if (game->checkCollisionsNaive) {
		manager->checkCollisionsNaive(game);
	}
	else {
		manager->checkCollisionsQuadtree(game);
	}
}
