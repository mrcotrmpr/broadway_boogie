#ifndef LOAD_ARTISTS_COMMAND_HPP
#define LOAD_ARTISTS_COMMAND_HPP

#include "command.hpp"
#include "../../managers/artist_manager.hpp"

class LoadArtistCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
private:
    std::shared_ptr<ArtistManager> manager = std::make_shared<ArtistManager>();
};

#endif // LOAD_ARTISTS_COMMAND_HPP
