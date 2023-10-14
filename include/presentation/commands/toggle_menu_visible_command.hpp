#ifndef TOGGLE_MENU_VISIBLE_COMMAND_HPP
#define TOGGLE_MENU_VISIBLE_COMMAND_HPP

#include "command.hpp"

class ToggleMenuVisibleCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) override;
};

#endif // TOGGLE_MENU_VISIBLE_COMMAND_HPP
