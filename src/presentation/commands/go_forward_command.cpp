#include "presentation/commands/go_forward_command.hpp"
#include "presentation/sdl_facade.hpp"
#include "presentation/game.hpp"
#include <iostream>

void GoForwardCommand::execute(std::shared_ptr<Game> game) {
    if (game->currentMementoIndex == -1) {
        game->currentMementoIndex = game->sdl->mementoManager->getMementosCount() - 1;
    }

    int currentMementoIndex = game->currentMementoIndex;
    if (currentMementoIndex < game->sdl->mementoManager->getMementosCount() - 1) {
        auto memento = game->sdl->mementoManager->getMemento(currentMementoIndex + 1);
        game->currentMementoIndex = currentMementoIndex + 1;
        std::cout << "Current index: " << game->currentMementoIndex << "/" << game->sdl->mementoManager->getMementosCount() - 1 << std::endl;
        game->restoreMemento(memento);
        game->sdl->render();
    }
    else {
        game->atPresent = true;
        game->currentMementoIndex = -1;
        std::cout << "No more states to go forward to." << std::endl;
    }
}
