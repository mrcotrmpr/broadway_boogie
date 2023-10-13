#ifndef MUSEUM_MANAGER_HPP
#define MUSEUM_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <SDL.h>
#include "domain/museum.hpp"

class MuseumManager {
public:
    void renderMuseum(SDL_Renderer* renderer, std::shared_ptr<Museum> museum, float scaleX, float scaleY);
};

#endif // MUSEUM_MANAGER_HPP
