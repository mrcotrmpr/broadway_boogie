#include "presentation/sdl_facade.hpp"
#include <iostream>
#include <unordered_map>
#include <cstdlib>

SDLFacade::SDLFacade() : window(nullptr), renderer(nullptr), initialized(false) {}

SDLFacade::~SDLFacade() {
    cleanup();
}

bool SDLFacade::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    initialized = true;
    return true;
}

bool SDLFacade::createWindow(const std::string& title, int width, int height) {
    if (!initialized) {
        std::cerr << "SDL not initialized. Call init() first." << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void SDLFacade::render(std::vector<std::shared_ptr<Artist>> artists, std::shared_ptr<Museum> museum) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int windowWidth = 800;
    int windowHeight = 800;
    float scaleX = static_cast<float>(windowWidth) / 53.0f;
    float scaleY = static_cast<float>(windowHeight) / 53.0f;

    renderMuseum(museum, scaleX, scaleY);
    renderArtists(artists, scaleX, scaleY);
    moveArtistsRandomly(artists);

    SDL_RenderPresent(renderer);
}

void SDLFacade::renderMuseum(std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    std::unordered_map<char, std::shared_ptr<NodeType>> nodeTypeMap;
    for (auto type : museum->nodeTypes) {
        nodeTypeMap[type->tag] = type;
    }

    for (const auto& node : museum->nodes) {
        auto nodeTypeIt = nodeTypeMap.find(node->tag);

        if (nodeTypeIt != nodeTypeMap.end()) {
            SDL_SetRenderDrawColor(renderer, nodeTypeIt->second->red, nodeTypeIt->second->green, nodeTypeIt->second->blue, 255);
        }
        else {
            SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255); // Default to purple if node type not found
        }

        // Calculate the screen coordinates of the node
        SDL_Rect nodeRect;
        nodeRect.x = static_cast<int>(node->x * scaleX);
        nodeRect.y = static_cast<int>(node->y * scaleY);
        nodeRect.w = 14;
        nodeRect.h = 14;
        SDL_RenderFillRect(renderer, &nodeRect);

        // Draw edges
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (const auto& edge : node->edges) {
            SDL_RenderDrawLine(renderer,
                static_cast<int>(node->x * scaleX),
                static_cast<int>(node->y * scaleY),
                static_cast<int>(edge->x * scaleX),
                static_cast<int>(edge->y * scaleY)
            );
        }
    }
}

void SDLFacade::renderArtists(std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY) {
    // Render artists
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& artist : artists) {
        SDL_Rect artistRect;
        artistRect.x = static_cast<int>(artist->x * scaleX);
        artistRect.y = static_cast<int>(artist->y * scaleY);
        artistRect.w = 7;
        artistRect.h = 7;
        SDL_RenderFillRect(renderer, &artistRect);
    }
}

void SDLFacade::moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists) {
    for (auto& artist : artists) {
        int direction = rand() % 4;

        int vx = artist->vx;
        int vy = artist->vy;

        switch (direction) {
        case 0: // Move north
            vy = -1;
            break;
        case 1: // Move east
            vx = 1;
            break;
        case 2: // Move south
            vy = 1;
            break;
        case 3: // Move west
            vx = -1;
            break;
        }
        artist->x += vx * 0.2f;
        artist->y += vy * 0.2f;
    }
}


bool SDLFacade::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void SDLFacade::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    if (initialized) {
        SDL_Quit();
    }
}
