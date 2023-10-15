#include "presentation/commands/go_forward_command.hpp"
#include "presentation/sdl_facade.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "presentation/game.hpp"
#include <iostream>

void GoForwardCommand::execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) {
    if (game->currentMementoIndex == -1) {
        game->currentMementoIndex = game->sdl->mementoManager->getMementosCount() - 1;
    }

    std::cout << "Current index: " << game->currentMementoIndex << "/" << game->sdl->mementoManager->getMementosCount() - 1 << std::endl;

    int currentMementoIndex = game->currentMementoIndex;
    if (currentMementoIndex < game->sdl->mementoManager->getMementosCount() - 1) {
        auto memento = game->sdl->mementoManager->getMemento(currentMementoIndex + 1);
        game->currentMementoIndex = currentMementoIndex + 1;
        game->restoreMemento(memento);
        std::cout << "Went forward to next state." << std::endl;

    }
    else {
        game->atPresent = true;
        game->currentMementoIndex = -1;
        std::cout << "No more states to go forward to." << std::endl;
    }
}
