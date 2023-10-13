#include "domain/states/blue_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void BlueState::handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) {
    std::cout << "Handle blue state" << std::endl;
}
