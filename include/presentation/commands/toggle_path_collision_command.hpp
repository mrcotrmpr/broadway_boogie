#ifndef TOGGLE_PATH_COLLISION_COMMAND_HPP
#define TOGGLE_PATH_COLLISION_COMMAND_HPP

#include "presentation/commands/command.hpp"

class TogglePathCollisionCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // TOGGLE_PATH_COLLISION_COMMAND_HPP
