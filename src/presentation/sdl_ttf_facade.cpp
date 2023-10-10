#include "presentation/sdl_ttf_facade.hpp"

SDLTTFFacade::SDLTTFFacade() : font(nullptr) {}

SDLTTFFacade::~SDLTTFFacade() {
    cleanup();
}

bool SDLTTFFacade::init() {
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

bool SDLTTFFacade::loadFont(const std::string& fontPath, int fontSize) {
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void SDLTTFFacade::renderText(SDL_Renderer* renderer, const std::string& text, const SDL_Rect& destRect) {
    TTF_Font* font = TTF_OpenFont("C:\\Users\\marco\\source\\repos\\test\\data\\fonts\\Roboto-Regular.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    if (!font) {
        std::cerr << "Font not loaded." << std::endl;
        return;
    }

    SDL_Color textColor = { 255, 255, 255, 255 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if (!textSurface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        return;
    }

    SDL_RenderCopy(renderer, textTexture, NULL, &destRect);

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}


void SDLTTFFacade::cleanup() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    TTF_Quit();
}
