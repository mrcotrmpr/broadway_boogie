#include "presentation/commands/set_pathfinding_end_command.hpp"
#include <iostream>

void SetPathFindingEndCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    std::shared_ptr<Node> currentNode = game->getNode(x, y, game->scaleX, game->scaleY);
    if (currentNode) {
        std::cout << "Pathfinding end set at node with x, y:" << currentNode->x << ", " << currentNode->y << std::endl;
        game->pathFindingEnd = currentNode;
    }
}
