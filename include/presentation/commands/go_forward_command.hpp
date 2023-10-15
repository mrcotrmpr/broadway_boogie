#ifndef GO_FORWARD_COMMAND_HPP
#define GO_FORWARD_COMMAND_HPP

#include "presentation/commands/command.hpp"

class GoForwardCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // GO_FORWARD_COMMAND_HPP
