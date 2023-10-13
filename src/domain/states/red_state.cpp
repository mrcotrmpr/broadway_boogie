#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/red_state.hpp"
#include "domain/states/blue_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void RedState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
	// Remove artist
	game->removeArtist(artist);

	// Change node to blue
	node->tag = 'B';
	node->state = std::make_shared<BlueState>();
}
