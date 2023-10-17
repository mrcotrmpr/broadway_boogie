#include "presentation/commands/toggle_render_quadtree_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleRenderQuadtreeCommand::execute(std::shared_ptr<Game> game)
{
	game->renderQuadtree = !game->renderQuadtree;
}
