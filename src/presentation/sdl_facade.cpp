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

    // Define the coordinates and dimensions of a white rectangle
    SDL_Rect whiteRect;
    whiteRect.x = 100; // X-coordinate of the top-left corner
    whiteRect.y = 100; // Y-coordinate of the top-left corner
    whiteRect.w = 200; // Width of the rectangle
    whiteRect.h = 200; // Height of the rectangle

    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Fill the rectangle with white color
    SDL_RenderFillRect(renderer, &whiteRect);

    // Present the rendered content
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
