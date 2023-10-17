#include "managers/command_manager.hpp"

CommandManager::CommandManager()
{
    // Create instances of the commands and register them
    auto loadDocumentsCommand = std::make_shared<LoadDocumentsCommand>();
    auto toggleArtistMovingCommand = std::make_shared<ToggleArtistsMovingCommand>();
    auto toggleRenderArtistsCommand = std::make_shared<ToggleRenderArtistsCommand>();
    auto toggleMenuVisibleCommand = std::make_shared<ToggleMenuVisibleCommand>();
    auto handleNodeInteractionCommand = std::make_shared<HandleNodeInteractionCommand>();
    auto goForwardCommand = std::make_shared<GoForwardCommand>();
    auto goBackCommand = std::make_shared<GoBackCommand>();
    auto setPathFindingStartCommand = std::make_shared<SetPathFindingStartCommand>();
    auto setPathFindingEndCommand = std::make_shared<SetPathFindingEndCommand>();
    auto togglePathFindingEndCommand = std::make_shared<TogglePathfindingCommand>();
    auto toggleCollisionCommand = std::make_shared<ToggleCollisionCommand>();
    auto doCollisionCommand = std::make_shared<DoCollisionCommand>();
    auto toggleRenderPathCommand = std::make_shared<ToggleRenderPathCommand>();
    auto toggleRenderVisitedCommand = std::make_shared<ToggleRenderVisitedCommand>();

    // Register the commands with their respective keys
    registerCommand(SDLK_o, loadDocumentsCommand);
    registerCommand(SDLK_a, toggleRenderArtistsCommand);
    registerCommand(SDLK_SPACE, toggleArtistMovingCommand);
    registerCommand(SDLK_m, toggleMenuVisibleCommand);
    registerCommand(SDLK_RETURN, handleNodeInteractionCommand);
    registerCommand(SDLK_LEFT, goBackCommand);
    registerCommand(SDLK_RIGHT, goForwardCommand);
    registerCommand(SDLK_d, togglePathFindingEndCommand);
    registerCommand(SDL_BUTTON_LEFT, setPathFindingStartCommand);
    registerCommand(SDL_BUTTON_RIGHT, setPathFindingEndCommand);
    registerCommand(SDLK_c, toggleCollisionCommand);
    registerCommand(SDLK_q, doCollisionCommand);
    registerCommand(SDLK_p, toggleRenderPathCommand);
    registerCommand(SDLK_v, toggleRenderVisitedCommand);
}

void CommandManager::registerCommand(SDL_Keycode key, std::shared_ptr<Command> command)
{
	commandMap[key] = command;
}
