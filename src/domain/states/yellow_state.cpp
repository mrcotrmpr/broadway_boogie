#include "domain/states/yellow_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void YellowState::handleInteraction(std::shared_ptr<Game> game) {
    game->printArtists();
}
