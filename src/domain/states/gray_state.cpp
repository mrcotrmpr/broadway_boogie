#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/gray_state.hpp"
#include "domain/states/red_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void GrayState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
    node->tag = 'R'; // Change node to red
    node->state = std::make_shared<RedState>();
}
