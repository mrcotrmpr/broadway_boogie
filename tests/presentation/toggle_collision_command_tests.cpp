#include <gtest/gtest.h>
#include "presentation/commands/toggle_collision_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleCollisionCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleCollisionCommand = std::make_shared<ToggleCollisionCommand>();

    game->checkCollisionsNaive = false;

    toggleCollisionCommand->execute(game);
    ASSERT_TRUE(game->checkCollisionsNaive);

    toggleCollisionCommand->execute(game);
    ASSERT_FALSE(game->checkCollisionsNaive);
}
