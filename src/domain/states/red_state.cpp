#include "domain/states/red_state.hpp"
#include <iostream>

void RedState::handleInteraction(std::shared_ptr<Game> game) {
    std::cout << "Handle red state" << std::endl;
}
