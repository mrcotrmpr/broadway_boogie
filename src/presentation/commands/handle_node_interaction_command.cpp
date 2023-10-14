#include "presentation/commands/handle_node_interaction_command.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void HandleNodeInteractionCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    std::shared_ptr<Node> currentNode = game->getNode(x, y, game->scaleX, game->scaleY);
    if (currentNode) {
        currentNode->state->handleInteraction(game, currentNode, nullptr);
    }
}
