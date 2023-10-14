#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
#include <string>
#include "domain/artist.hpp"
#include "domain/museum.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "managers/overlay_manager.hpp"
#include "presentation/game.hpp"

class Artist;
class Museum;

class SDLFacade {
public:
    SDLFacade();
    ~SDLFacade();
    bool init(std::shared_ptr<Game> game);
    bool createWindow(const std::string& title, int width, int height);
    void render();
    bool handleEvents();
    void handleKeyPress(SDL_Keycode key);
    void cleanup();
    int windowWidth = 800;
    int windowHeight = 800;
    float scaleX = static_cast<float>(windowWidth) / 53.0f;
    float scaleY = static_cast<float>(windowHeight) / 53.0f;
private:
    std::shared_ptr<Game> gameState = nullptr;
    std::shared_ptr<MuseumManager> museumManager;
    std::shared_ptr<ArtistManager> artistManager;
    std::shared_ptr<OverlayManager> overlayManager;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
    bool artistsMoving = false;
    bool menuVisible = false;
};

#endif // SDL_FACADE_HPP
