#ifndef LOAD_DOCUMENTS_COMMAND_HPP
#define LOAD_DOCUMENTS_COMMAND_HPP

#include "presentation/commands/command.hpp"
#include "../../managers/museum_manager.hpp"
#include "../../managers/artist_manager.hpp"

class LoadDocumentsCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
private:
    std::shared_ptr<MuseumManager> museumManager = std::make_shared<MuseumManager>();
    std::shared_ptr<ArtistManager> artistManager = std::make_shared<ArtistManager>();
};

#endif // LOAD_DOCUMENTS_COMMAND_HPP
