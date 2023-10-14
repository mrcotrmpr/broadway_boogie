#ifndef HANDLE_NODE_INTERACTION_COMMAND_HPP
#define HANDLE_NODE_INTERACTION_COMMAND_HPP

#include "command.hpp"
#include <SDL.h>

class HandleNodeInteractionCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // HANDLE_NODE_INTERACTION_COMMAND_HPP
