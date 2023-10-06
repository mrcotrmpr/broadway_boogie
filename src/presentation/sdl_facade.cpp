#include "presentation/sdl_facade.hpp"
#include <iostream>

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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Define the scale factor based on the window dimensions
    int windowWidth = 800;
    int windowHeight = 800;
    float scaleX = static_cast<float>(windowWidth) / 53.0f; // Scale factor for X
    float scaleY = static_cast<float>(windowHeight) / 53.0f; // Scale factor for Y

    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Render artists with scaling
    for (const auto& artist : artists) {
        SDL_Rect artistRect;
        // Scale the artist's position
        artistRect.x = static_cast<int>(artist->x * scaleX);
        artistRect.y = static_cast<int>(artist->y * scaleY);
        // Scale the artist's size based on the grid cell size
        artistRect.w = static_cast<int>(50);
        artistRect.h = static_cast<int>(50);
        SDL_RenderFillRect(renderer, &artistRect);
    }

    for (const auto& node : museum->nodes) {
        //TODO: adjust RGB based on NodeType
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

        // Calculate the screen coordinates of the node
        SDL_Rect nodeRect;
        nodeRect.x = static_cast<int>(node->x * scaleX);
        nodeRect.y = static_cast<int>(node->y * scaleY);
        nodeRect.w = 50;
        nodeRect.h = 50;
        SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255); // Red color for edges
        SDL_RenderDrawRect(renderer, &nodeRect);

        // TODO: check if this actually works
        // Draw edges as dark blue lines
        for (const auto& edge : node->edges) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderDrawLine(renderer,
                static_cast<int>(node->x * scaleX),
                static_cast<int>(node->y * scaleY),
                static_cast<int>(edge->x * scaleX),
                static_cast<int>(edge->y * scaleY)
            );
        }

    }

    SDL_RenderPresent(renderer);
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
