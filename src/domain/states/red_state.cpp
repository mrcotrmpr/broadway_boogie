#include "domain/states/red_state.hpp"
#include <iostream>

void RedState::handleInteraction(std::shared_ptr<SDLFacade> sdl) {
    std::cout << "Handle red state" << std::endl;
}
