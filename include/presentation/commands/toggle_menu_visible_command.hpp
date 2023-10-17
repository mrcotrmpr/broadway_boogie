#ifndef TOGGLE_MENU_VISIBLE_COMMAND_HPP
#define TOGGLE_MENU_VISIBLE_COMMAND_HPP

#include "presentation/commands/command.hpp"

class ToggleMenuVisibleCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // TOGGLE_MENU_VISIBLE_COMMAND_HPP
