#include "presentation/commands/toggle_render_visited_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleRenderVisitedCommand::execute(std::shared_ptr<Game> game)
{
	game->renderVisited = !game->renderVisited;
}
