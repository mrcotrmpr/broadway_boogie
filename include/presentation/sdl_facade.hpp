#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
#include <string>
#include "domain/artist.hpp"
#include "domain/museum.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "managers/overlay_manager.hpp"
#include "managers/command_manager.hpp"
#include "managers/pathfinding_manager.hpp"
#include "managers/collision_manager.hpp"
#include "memento/caretaker.hpp"
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
    std::shared_ptr<Caretaker> mementoManager;
private:
    std::shared_ptr<Game> gameState = nullptr;
    std::shared_ptr<MuseumManager> museumManager;
    std::shared_ptr<ArtistManager> artistManager;
    std::shared_ptr<OverlayManager> overlayManager;
    std::shared_ptr<CommandManager> commandManager;
    std::shared_ptr<PathfindingManager> pathfindingManager;
    std::shared_ptr<CollisionManager> collisionManager;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
    int tickCounter = 0;
};

#endif // SDL_FACADE_HPP
