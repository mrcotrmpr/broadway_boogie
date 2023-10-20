#include <gtest/gtest.h>
#include "presentation/commands/toggle_render_quadtree_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleRenderQuadtreeCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleRenderQuadtreeCommand = std::make_shared<ToggleRenderQuadtreeCommand>();

    game->renderQuadtree = false;

    toggleRenderQuadtreeCommand->execute(game);
    ASSERT_TRUE(game->renderQuadtree);

    toggleRenderQuadtreeCommand->execute(game);
    ASSERT_FALSE(game->renderQuadtree);
}
