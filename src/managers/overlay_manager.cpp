#include "managers/overlay_manager.hpp"

OverlayManager::OverlayManager()
{
    ttf->init();
}

void OverlayManager::renderOverlayMenu(SDL_Renderer* renderer, std::shared_ptr<Game> game) {
    if (game->menuVisible) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200); // Black with some transparency
        SDL_Rect menuRect;
        menuRect.x = 10;
        menuRect.y = 10;
        menuRect.w = 180;
        menuRect.h = 100;
        SDL_RenderFillRect(renderer, &menuRect);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

        SDL_Rect textRect;
        textRect.x = 20;
        textRect.y = 20;
        textRect.w = 160;
        textRect.h = 20;

        game->artistsMoving ? ttf->renderText(renderer, "Artists moving: on", textRect) : ttf->renderText(renderer, "Artists moving: off", textRect);
        textRect.y += 30;

        game->breadthFirstSearch ? ttf->renderText(renderer, "Pathfinding: breadthFirstSearch", textRect) : ttf->renderText(renderer, "Pathfinding: dijkstra", textRect);
        textRect.y += 30;

        game->checkCollisionsNaive ? ttf->renderText(renderer, "Collision: naive", textRect) : ttf->renderText(renderer, "Collision: quadtree", textRect);
    }
}
