#include "presentation/commands/handle_node_interaction_command.hpp"
#include "presentation/game.hpp"
#include <iostream>

void HandleNodeInteractionCommand::execute(std::shared_ptr<Game> game)
{
    if (game->atPresent) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        std::shared_ptr<Node> currentNode = game->getNode(x, y, true);
        if (currentNode) {
            currentNode->state->handleInteraction(game, currentNode, nullptr);
        }
    }
}
