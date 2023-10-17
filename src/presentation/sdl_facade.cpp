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
    mementoManager = std::make_shared<Caretaker>();
    commandManager = std::make_shared<CommandManager>();
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

    if (gameState->atPresent)
    {
        tickCounter++;
        if (tickCounter == 10) {
            mementoManager->addMemento(gameState->createMemento());
            tickCounter = 0;
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    if (gameState->museum) {
        museumManager->renderMuseum(renderer, gameState->museum, gameState->scaleX, gameState->scaleY);
    }

    if (!gameState->artists.empty() && gameState->renderArtists) {
        artistManager->renderArtists(renderer, gameState->artists, gameState->scaleX, gameState->scaleY);
    }

    if (gameState->atPresent && gameState->renderArtists) {
        artistManager->moveArtistsRandomly(gameState->artists, gameState->artistsMoving);
        artistManager->detectCollisions(gameState, gameState->scaleX, gameState->scaleY, gameState->artistsMoving);
    }

    overlayManager->renderOverlayMenu(renderer, gameState);

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
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
            handleKeyPress(event.button.button);
        }
    }
    return true;
}

void SDLFacade::handleKeyPress(SDL_Keycode key) {
    auto it = commandManager->commandMap.find(key);
    if (it != commandManager->commandMap.end()) {
        it->second->execute(gameState);
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
