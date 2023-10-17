#include "presentation/commands/toggle_render_artists_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleRenderArtistsCommand::execute(std::shared_ptr<Game> game)
{
	game->renderArtists = !game->renderArtists;
}
