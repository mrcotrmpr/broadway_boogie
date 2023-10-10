#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "domain/artist.hpp"
#include "domain/museum.hpp"

class Artist;
class Museum;

class SDLFacade {
public:
    SDLFacade();
    ~SDLFacade();
    bool init();
    bool createWindow(const std::string& title, int width, int height);
    void render(std::vector<std::shared_ptr<Artist>> artists, std::shared_ptr<Museum> museum);
    void renderOverlayMenu();
    void renderText(const std::string& text, const SDL_Rect& destRect);
    void renderMuseum(std::shared_ptr<Museum> museum, float scaleX, float scaleY);
    void renderArtists(std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY);
    void moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists);
    void detectCollisions(std::vector<std::shared_ptr<Artist>>& artists, std::shared_ptr<Museum> museum, float scaleX, float scaleY);
    char getNodeTag(float x, float y, std::shared_ptr<Museum> museum, float scaleX, float scaleY);
    bool handleEvents();
    void handleKeyPress(SDL_Keycode key);
    void cleanup();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
    bool artistsMoving = false;
    bool menuVisible = false;
};

#endif // SDL_FACADE_HPP
