#include "domain/states/yellow_state.hpp"
#include <iostream>

void YellowState::handleInteraction(std::shared_ptr<SDLFacade> sdl) {
    std::cout << "Handle yellow state" << std::endl;
}
