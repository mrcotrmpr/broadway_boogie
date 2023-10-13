#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/blue_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void BlueState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
    std::cout << "Handle blue state" << std::endl;
    std::cout << "Node tag: " << node->tag << std::endl;
    std::cout << "Artist x & y: " << artist->x << ", " << artist->y << std::endl;
}
