#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
#include <string>

class SDLFacade {
public:
    SDLFacade();
    ~SDLFacade();
    bool init();
    bool createWindow(const std::string& title, int width, int height);
    void render();
    bool handleEvents();
    void cleanup();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
};

#endif // SDL_FACADE_HPP
