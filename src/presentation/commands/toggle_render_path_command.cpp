#include "presentation/commands/toggle_render_path_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleRenderPathCommand::execute(std::shared_ptr<Game> game)
{
	game->renderPath = !game->renderPath;
}
