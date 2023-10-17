#ifndef TOGGLE_PATHFINDING_COMMAND_HPP
#define TOGGLE_PATHFINDING_COMMAND_HPP

#include "presentation/commands/command.hpp"

class TogglePathfindingCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // TOGGLE_PATHFINDING_COMMAND_HPP
