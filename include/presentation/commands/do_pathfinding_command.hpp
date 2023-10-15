#ifndef DO_PATHFINDING_COMMAND
#define DO_PATHFINDING_COMMAND

#include "presentation/commands/command.hpp"
#include "../../managers/pathfinding_manager.hpp"
#include "presentation/game.hpp"

class DoPathFindingCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
private:
    std::shared_ptr<PathfindingManager> manager;
};

#endif // DO_PATHFINDING_COMMAND
