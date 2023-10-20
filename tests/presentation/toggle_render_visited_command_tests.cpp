#include <gtest/gtest.h>
#include "presentation/commands/toggle_render_visited_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleRenderVisitedCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleRenderVisitedCommand = std::make_shared<ToggleRenderVisitedCommand>();

    game->renderVisited = false;

    toggleRenderVisitedCommand->execute(game);
    ASSERT_TRUE(game->renderVisited);

    toggleRenderVisitedCommand->execute(game);
    ASSERT_FALSE(game->renderVisited);
}
