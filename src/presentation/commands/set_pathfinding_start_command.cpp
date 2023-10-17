#include "presentation/commands/set_pathfinding_start_command.hpp"
#include <iostream>

void SetPathFindingStartCommand::execute(std::shared_ptr<Game> game)
{
    if (game->museum && game->atPresent) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        std::shared_ptr<Node> currentNode = game->getNode(x, y, game->scaleX, game->scaleY);
        if (currentNode) {
            std::cout << "Pathfinding start set at node with x, y: " << currentNode->x << ", " << currentNode->y << std::endl;
            game->pathFindingStart = currentNode;
        }
    }
}
