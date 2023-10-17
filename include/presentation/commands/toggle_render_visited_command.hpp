#ifndef TOGGLE_RENDER_VISITED_COMMAND_HPP
#define TOGGLE_RENDER_VISITED_COMMAND_HPP

#include "presentation/commands/command.hpp"

class ToggleRenderVisitedCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // TOGGLE_RENDER_VISITED_COMMAND_HPP
