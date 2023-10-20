#include <gtest/gtest.h>
#include "presentation/commands/toggle_pathfinding_command.hpp"
#include "presentation/game.hpp"

TEST(TogglePathfindingCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto togglePathfindingCommand = std::make_shared<TogglePathfindingCommand>();

    game->breadthFirstSearch = false;

    togglePathfindingCommand->execute(game);
    ASSERT_TRUE(game->breadthFirstSearch);

    togglePathfindingCommand->execute(game);
    ASSERT_FALSE(game->breadthFirstSearch);
}
