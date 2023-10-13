#include "presentation/sdl_facade.hpp"
#include <iostream>
#include <utility>
#include <unordered_map>
#include <cstdlib>

SDLFacade::SDLFacade() : window(nullptr), renderer(nullptr), initialized(false) 
{
    museumManager = std::make_shared<MuseumManager>();
    artistManager = std::make_shared<ArtistManager>();
    overlayManager = std::make_shared<OverlayManager>();
}

SDLFacade::~SDLFacade() {
    cleanup();
}

bool SDLFacade::init(std::shared_ptr<Game> game) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    gameState = game;
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

void SDLFacade::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int windowWidth = 800;
    int windowHeight = 800;
    float scaleX = static_cast<float>(windowWidth) / 53.0f;
    float scaleY = static_cast<float>(windowHeight) / 53.0f;

    museumManager->renderMuseum(renderer, gameState->museum, scaleX, scaleY);
    artistManager->renderArtists(renderer, gameState->artists, scaleX, scaleY);
    artistManager->moveArtistsRandomly(gameState->artists, artistsMoving);
    artistManager->detectCollisions(gameState, scaleX, scaleY, artistsMoving);
    overlayManager->renderOverlayMenu(renderer, menuVisible, artistsMoving);

    SDL_RenderPresent(renderer);
}

bool SDLFacade::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
        else if (event.type == SDL_KEYDOWN) {
            handleKeyPress(event.key.keysym.sym);
        }
    }
    return true;
}

void SDLFacade::handleKeyPress(SDL_Keycode key) {
    switch (key) {
    case SDLK_SPACE:
        // Toggle the artistsMoving flag when the SPACE key is pressed
        artistsMoving = !artistsMoving;
        break;
    case SDLK_m:
        // Toggle the menuVisible flag when the 'M' key is pressed
        menuVisible = !menuVisible;
        break;
    }
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
