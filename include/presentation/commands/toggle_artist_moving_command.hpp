#ifndef TOGGLE_ARTISTS_MOVING_COMMAND_HPP
#define TOGGLE_ARTISTS_MOVING_COMMAND_HPP

#include "command.hpp"

class ToggleArtistsMovingCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // TOGGLE_ARTISTS_MOVING_COMMAND_HPP
