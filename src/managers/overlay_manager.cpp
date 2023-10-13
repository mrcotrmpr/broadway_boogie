#include "managers/overlay_manager.hpp"

OverlayManager::OverlayManager()
{
    ttf->init();
}

void OverlayManager::renderOverlayMenu(SDL_Renderer* renderer, bool menuVisible, bool artistsMoving) {
    if (menuVisible) {
        // Draw a background rectangle for the menu
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200); // Black with some transparency
        SDL_Rect menuRect;
        menuRect.x = 10;
        menuRect.y = 10;
        menuRect.w = 180;
        menuRect.h = 50;
        SDL_RenderFillRect(renderer, &menuRect);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

        // Render the menu text
        SDL_Rect textRect;
        textRect.x = 20;
        textRect.y = 20;
        textRect.w = 160;
        textRect.h = 20;

        if (artistsMoving) {
            ttf->renderText(renderer, "Artists moving: on", textRect);
        }
        else {
            ttf->renderText(renderer, "Artists moving: off", textRect);
        }
    }
}
