#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>

class Game;
class MuseumManager;
class ArtistManager;

class Command {
public:
    virtual void execute(std::shared_ptr<Game> game, std::shared_ptr<MuseumManager> museumManager, std::shared_ptr<ArtistManager> artistManager) = 0;
    virtual ~Command() = default;
};

#endif // COMMAND_HPP
