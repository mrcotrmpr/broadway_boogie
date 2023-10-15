#ifndef LOAD_MUSEUM_COMMAND_HPP
#define LOAD_MUSEUM_COMMAND_HPP

#include "presentation/commands/command.hpp"
#include "../../managers/museum_manager.hpp"

class LoadMuseumCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
private:
    std::shared_ptr<MuseumManager> manager = std::make_shared<MuseumManager>();
};

#endif // LOAD_MUSEUM_COMMAND_HPP
