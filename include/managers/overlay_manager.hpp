#ifndef OVERLAY_MANAGER_HPP
#define OVERLAY_MANAGER_HPP

#include <SDL.h>
#include <memory>
#include "../presentation/game.hpp"
#include "../presentation/sdl_ttf_facade.hpp"

class OverlayManager {
public:
    OverlayManager();
    void renderOverlayMenu(SDL_Renderer* renderer, std::shared_ptr<Game> game);
    std::shared_ptr<SDLTTFFacade> ttf = std::make_shared<SDLTTFFacade>();
};

#endif // OVERLAY_MANAGER_HPP
