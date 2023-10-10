#ifndef SDL_TTF_FACADE_HPP
#define SDL_TTF_FACADE_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class SDLTTFFacade {
public:
    SDLTTFFacade();
    ~SDLTTFFacade();

    bool init();
    bool loadFont(const std::string& fontPath, int fontSize);
    void renderText(SDL_Renderer* renderer, const std::string& text, const SDL_Rect& destRect);
    void cleanup();

private:
    TTF_Font* font;
};

#endif // SDL_TTF_FACADE_HPP
