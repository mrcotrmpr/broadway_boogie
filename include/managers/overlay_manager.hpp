#ifndef OVERLAY_MANAGER_HPP
#define OVERLAY_MANAGER_HPP

#include <SDL.h>
#include "../presentation/sdl_ttf_facade.hpp"

class OverlayManager {
public:
    OverlayManager();
    void renderOverlayMenu(SDL_Renderer* renderer, bool menuVisible, bool artistsMoving, bool breadthFirstSearch);
    std::shared_ptr<SDLTTFFacade> ttf = std::make_shared<SDLTTFFacade>();
};

#endif // OVERLAY_MANAGER_HPP
