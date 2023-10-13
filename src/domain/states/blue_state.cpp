#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/blue_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void BlueState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
    // Find orthogonal nodes
    for (const auto& otherNode : game->museum->nodes) {
        if ((otherNode->x == node->x && (otherNode->y == node->y - 1 || otherNode->y == node->y + 1)) ||
            (otherNode->y == node->y && (otherNode->x == node->x - 1 || otherNode->x == node->x + 1))) {
            otherNode->tag = 'B'; // Set color to blue
        }
    }

    // Change node color to blue
    node->tag = 'Y';
}
