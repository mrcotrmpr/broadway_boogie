#ifndef COMMAND_MANAGER_HPP
#define COMMAND_MANAGER_HPP

#include "presentation/commands/command.hpp"
#include "presentation/commands/load_documents_command.hpp"
#include "presentation/commands/toggle_artist_moving_command.hpp"
#include "presentation/commands/toggle_render_artists_command.hpp"
#include "presentation/commands/toggle_menu_visible_command.hpp"
#include "presentation/commands/handle_node_interaction_command.hpp"
#include "presentation/commands/go_forward_command.hpp"
#include "presentation/commands/go_back_command.hpp"
#include "presentation/commands/set_pathfinding_start_command.hpp"
#include "presentation/commands/set_pathfinding_end_command.hpp"
#include "presentation/commands/toggle_pathfinding_command.hpp"
#include "presentation/commands/toggle_collision_command.hpp"
#include "presentation/commands/do_collision_command.hpp"
#include "presentation/commands/toggle_render_path_command.hpp"
#include "presentation/commands/toggle_render_visited_command.hpp"
#include <unordered_map>
#include <SDL.h>

class CommandManager {
public:
    CommandManager();
    void registerCommand(SDL_Keycode key, std::shared_ptr<Command> command);
    std::unordered_map<SDL_Keycode, std::shared_ptr<Command>> commandMap;
};

#endif // COMMAND_MANAGER_HPP
