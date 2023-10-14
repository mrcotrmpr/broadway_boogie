#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/yellow_state.hpp"
#include "domain/states/gray_state.hpp"
#include "presentation/game.hpp"
#include "factories/artist_factory.hpp"
#include <iostream>

void YellowState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
	
	if (node->interactions == 2) {
		// Make node gray
		node->tag = 'G';
		node->interactions = 0;
		node->state = std::make_shared<GrayState>();
	}
	else {
		node->interactions++;

		// Create new artist
		float x = artist->x;
		float y = artist->y;
		float vx = 0;
		float vy = 0;

		auto newArtist = ArtistFactory::createArtist(x, y, vx, vy);
		game->newArtists.push_back(newArtist);
	}
}
