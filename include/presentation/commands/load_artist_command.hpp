#ifndef LOAD_ARTISTS_COMMAND_HPP
#define LOAD_ARTISTS_COMMAND_HPP

#include "command.hpp"

class LoadArtistsCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
};

#endif // LOAD_ARTISTS_COMMAND_HPP
