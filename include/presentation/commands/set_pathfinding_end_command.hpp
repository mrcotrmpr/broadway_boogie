#ifndef SET_PATH_FINDING_END_COMMAND_HPP
#define SET_PATH_FINDING_END_COMMAND_HPP

#include "presentation/commands/command.hpp"
#include "presentation/game.hpp"
#include <SDL.h>

class SetPathFindingEndCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // SET_PATH_FINDING_END_COMMAND_HPP
