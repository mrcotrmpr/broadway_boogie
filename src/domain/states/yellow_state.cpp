#include "domain/states/yellow_state.hpp"
#include "presentation/game.hpp"
#include <iostream>

void YellowState::handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) {
	std::cout << "Handle yellow state" << std::endl;
}
