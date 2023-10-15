#ifndef GO_BACK_COMMAND_HPP
#define GO_BACK_COMMAND_HPP

#include "presentation/commands/command.hpp"

class GoBackCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // GO_BACK_COMMAND_HPP
