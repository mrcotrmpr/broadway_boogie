#ifndef LOAD_ARTISTS_COMMAND_HPP
#define LOAD_ARTISTS_COMMAND_HPP

#include "command.hpp"

class LoadArtistCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // LOAD_ARTISTS_COMMAND_HPP
