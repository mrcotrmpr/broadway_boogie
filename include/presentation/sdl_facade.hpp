#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
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
    void renderMuseum(std::shared_ptr<Museum> museum, float scaleX, float scaleY);
    void renderArtists(std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY);
    void moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists);
    bool handleEvents();
    void cleanup();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
};

#endif // SDL_FACADE_HPP
