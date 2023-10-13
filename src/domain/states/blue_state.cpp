#include "domain/states/blue_state.hpp"
#include <iostream>

void BlueState::handleInteraction(std::shared_ptr<Game> game) {
    std::cout << "Handle blue state" << std::endl;
}
