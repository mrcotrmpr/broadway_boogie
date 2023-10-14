#include "presentation/commands/toggle_artist_moving_command.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void ToggleArtistsMovingCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
	game->artistsMoving = !game->artistsMoving;
}
