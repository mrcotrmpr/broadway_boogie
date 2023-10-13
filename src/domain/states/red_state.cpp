#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/red_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void RedState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
    // Remove artist from the game
    auto it = std::find(game->artists.begin(), game->artists.end(), artist);
    if (it != game->artists.end()) {
        game->artists.erase(it);
    }
    else {
        std::cout << "[RED STATE] Artist not found." << std::endl;
    }

    // Change node color to blue
    node->tag = 'B';
}
