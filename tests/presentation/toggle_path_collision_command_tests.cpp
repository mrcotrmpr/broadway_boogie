#include <gtest/gtest.h>
#include "presentation/commands/toggle_path_collision_command.hpp"
#include "presentation/game.hpp"

TEST(TogglePathCollisionCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto togglePathCollisionCommand = std::make_shared<TogglePathCollisionCommand>();

    game->pathCollision = false;

    togglePathCollisionCommand->execute(game);
    ASSERT_TRUE(game->pathCollision);

    togglePathCollisionCommand->execute(game);
    ASSERT_FALSE(game->pathCollision);
}
