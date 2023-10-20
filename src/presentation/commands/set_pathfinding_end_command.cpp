#include "presentation/commands/set_pathfinding_end_command.hpp"
#include <iostream>

void SetPathFindingEndCommand::execute(std::shared_ptr<Game> game)
{
    if (game->museum && game->atPresent) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        std::shared_ptr<Node> currentNode = game->getNode(x, y, true);
        if (currentNode) {
            std::cout << "Pathfinding end set at node with x, y: " << currentNode->x << ", " << currentNode->y << std::endl;
            game->pathFindingEnd = currentNode;
        }
    }
}
