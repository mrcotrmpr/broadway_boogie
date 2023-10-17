#include "managers/overlay_manager.hpp"

OverlayManager::OverlayManager()
{
    ttf->init();
}

void OverlayManager::renderOverlayMenu(SDL_Renderer* renderer, std::shared_ptr<Game> game) {
    if (game->menuVisible) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
        SDL_Rect menuRect;
        menuRect.x = 10;
        menuRect.y = 10;
        menuRect.w = 180;
        menuRect.h = 180;
        SDL_RenderFillRect(renderer, &menuRect);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_Rect textRect;
        textRect.x = 20;
        textRect.y = 20;
        textRect.w = 160;
        textRect.h = 15;

        game->artistsMoving ? ttf->renderText(renderer, "Artists moving: on", textRect) : ttf->renderText(renderer, "Artists moving: off", textRect);
        textRect.y += 20;
        game->breadthFirstSearch ? ttf->renderText(renderer, "Pathfinding: breadthFirstSearch", textRect) : ttf->renderText(renderer, "Pathfinding: dijkstra", textRect);
        textRect.y += 20;
        game->checkCollisionsNaive ? ttf->renderText(renderer, "Collision: naive", textRect) : ttf->renderText(renderer, "Collision: quadtree", textRect);
        textRect.y += 20;
        game->renderArtists ? ttf->renderText(renderer, "Render Artists: on", textRect) : ttf->renderText(renderer, "Render Artists: off", textRect);
        textRect.y += 20;
        game->renderPath ? ttf->renderText(renderer, "Render Path: on", textRect) : ttf->renderText(renderer, "Render Path: off", textRect);
        textRect.y += 20;
        game->renderVisited ? ttf->renderText(renderer, "Render Visited: on", textRect) : ttf->renderText(renderer, "Render Visited: off", textRect);
        textRect.y += 20;
        game->renderQuadtree ? ttf->renderText(renderer, "Render Quadtree: on", textRect) : ttf->renderText(renderer, "Render Quadtree: off", textRect);
        textRect.y += 20;
        game->pathCollision ? ttf->renderText(renderer, "Path Collision: on", textRect) : ttf->renderText(renderer, "Path Collision: off", textRect);
    }
}
