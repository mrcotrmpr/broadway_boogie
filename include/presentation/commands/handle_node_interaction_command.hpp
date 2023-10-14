#ifndef HANDLE_NODE_INTERACTION_COMMAND_HPP
#define HANDLE_NODE_INTERACTION_COMMAND_HPP

#include "command.hpp"

class HandleNodeInteractionCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // HANDLE_NODE_INTERACTION_COMMAND_HPP
