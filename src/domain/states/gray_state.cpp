#include "domain/states/gray_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void GrayState::handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) {
    std::cout << "Handle gray state" << std::endl;
}
