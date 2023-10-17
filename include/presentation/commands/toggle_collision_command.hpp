#ifndef TOGGLE_COLLISION_COMMAND_HPP
#define TOGGLE_COLLISION_COMMAND_HPP

#include "presentation/commands/command.hpp"

class ToggleCollisionCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // TOGGLE_COLLISION_COMMAND_HPP
