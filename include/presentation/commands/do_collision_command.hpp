#ifndef DO_COLLISION_COMMAND
#define DO_COLLISION_COMMAND

#include "presentation/commands/command.hpp"
#include "../../managers/collision_manager.hpp"
#include "presentation/game.hpp"

class DoCollisionCommand : public Command {
public:
    void execute(std::shared_ptr<Game> game) override;
private:
    std::shared_ptr<CollisionManager> manager;
};

#endif // DO_COLLISION_COMMAND
