#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/blue_state.hpp"
#include "domain/states/yellow_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void BlueState::handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) {
    if (artist) {
        for (const auto& otherNode : game->museum->nodes) {
            if (otherNode != node) {
                if (artist->direction == 1 && otherNode->x == node->x && (otherNode->y == node->y - 1 || otherNode->y == node->y + 1)) {
                    otherNode->tag = 'B'; // Change node to blue
                    otherNode->state = std::make_shared<BlueState>();
                }
                else if (artist->direction == 2 && otherNode->y == node->y && (otherNode->x == node->x - 1 || otherNode->x == node->x + 1)) {
                    otherNode->tag = 'B'; // Change node to blue
                    otherNode->state = std::make_shared<BlueState>();
                }
                else if (artist->direction == 3 && otherNode->x == node->x && (otherNode->y == node->y - 1 || otherNode->y == node->y + 1)) {
                    otherNode->tag = 'B'; // Change node to blue
                    otherNode->state = std::make_shared<BlueState>();
                }
                else if (artist->direction == 4 && otherNode->y == node->y && (otherNode->x == node->x - 1 || otherNode->x == node->x + 1)) {
                    otherNode->tag = 'B'; // Change node to blue
                    otherNode->state = std::make_shared<BlueState>();
                }
            }
        }
    }
    else
    {
        int count = 0;
        for (const auto& otherNode : game->museum->nodes) {
            if (otherNode != node) {
                if (otherNode->x == node->x && (otherNode->y == node->y - 1 || otherNode->y == node->y + 1)) {
                    if (count < 2) {
                        otherNode->tag = 'B'; // Change node to blue
                        otherNode->state = std::make_shared<BlueState>();
                        count++;
                    }
                }
                else if (otherNode->y == node->y && (otherNode->x == node->x - 1 || otherNode->x == node->x + 1)) {
                    if (count < 2) {
                        otherNode->tag = 'B'; // Change node to blue
                        otherNode->state = std::make_shared<BlueState>();
                        count++;
                    }
                }
            }
        }
    }

    // Change node to yellow
    node->tag = 'Y';
    node->state = std::make_shared<YellowState>();
}
