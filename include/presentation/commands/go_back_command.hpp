#ifndef GO_BACK_COMMAND_HPP
#define GO_BACK_COMMAND_HPP

#include "presentation/commands/command.hpp"

class GoBackCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // GO_BACK_COMMAND_HPP
