#ifndef SET_PATH_FINDING_START_COMMAND_HPP
#define SET_PATH_FINDING_START_COMMAND_HPP

#include "presentation/commands/command.hpp"
#include "presentation/game.hpp"
#include <SDL.h>

class SetPathFindingStartCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // SET_PATH_FINDING_START_COMMAND_HPP
