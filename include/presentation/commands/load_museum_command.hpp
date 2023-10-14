#ifndef LOAD_MUSEUM_COMMAND_HPP
#define LOAD_MUSEUM_COMMAND_HPP

#include "presentation/commands/command.hpp"

class LoadMuseumCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // LOAD_MUSEUM_COMMAND_HPP
