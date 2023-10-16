#include "managers/overlay_manager.hpp"

OverlayManager::OverlayManager()
{
    ttf->init();
}

void OverlayManager::renderOverlayMenu(SDL_Renderer* renderer, bool menuVisible, bool artistsMoving, bool breadthFirstSearch) {
    if (menuVisible) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200); // Black with some transparency
        SDL_Rect menuRect;
        menuRect.x = 10;
        menuRect.y = 10;
        menuRect.w = 180;
        menuRect.h = 70;
        SDL_RenderFillRect(renderer, &menuRect);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

        SDL_Rect textRect;
        textRect.x = 20;
        textRect.y = 20;
        textRect.w = 160;
        textRect.h = 20;

        if (artistsMoving) {
            ttf->renderText(renderer, "Artists moving: on", textRect);
            textRect.y += 30; // Update the y attribute to render the next text below
        }
        else {
            ttf->renderText(renderer, "Artists moving: off", textRect);
            textRect.y += 30; // Update the y attribute to render the next text below
        }

        if (breadthFirstSearch) {
            ttf->renderText(renderer, "Pathfinding: breadthFirstSearch", textRect);
        }
        else {
            ttf->renderText(renderer, "Pathfinding: dijkstra", textRect);
        }
    }
}
