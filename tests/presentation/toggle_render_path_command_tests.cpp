#include <gtest/gtest.h>
#include "presentation/commands/toggle_render_path_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleRenderPathCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleRenderPathCommand = std::make_shared<ToggleRenderPathCommand>();

    game->renderPath = false;

    toggleRenderPathCommand->execute(game);
    ASSERT_TRUE(game->renderPath);

    toggleRenderPathCommand->execute(game);
    ASSERT_FALSE(game->renderPath);
}
