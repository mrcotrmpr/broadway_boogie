#ifndef SDL_FACADE_HPP
#define SDL_FACADE_HPP

#include <SDL.h>
#include <unordered_map>
#include <string>
#include "domain/artist.hpp"
#include "domain/museum.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"
#include "managers/overlay_manager.hpp"
#include "presentation/game.hpp"
#include "presentation/commands/command.hpp"
#include "presentation/commands/load_museum_command.hpp"
#include "presentation/commands/load_artist_command.hpp"
#include "presentation/commands/toggle_artist_moving_command.hpp"
#include "presentation/commands/toggle_menu_visible_command.hpp"
#include "presentation/commands/handle_node_interaction_command.hpp"

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
    void registerCommand(SDL_Keycode key, std::shared_ptr<Command> command);
private:
    std::unordered_map<SDL_Keycode, std::shared_ptr<Command>> commandMap;
    std::shared_ptr<Game> gameState = nullptr;
    std::shared_ptr<MuseumManager> museumManager;
    std::shared_ptr<ArtistManager> artistManager;
    std::shared_ptr<OverlayManager> overlayManager;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool initialized;
};

#endif // SDL_FACADE_HPP
