#include <gtest/gtest.h>
#include "presentation/commands/toggle_menu_visible_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleMenuVisibleCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleMenuVisibleCommand = std::make_shared<ToggleMenuVisibleCommand>();

    game->menuVisible = false;

    toggleMenuVisibleCommand->execute(game);
    ASSERT_TRUE(game->menuVisible);

    toggleMenuVisibleCommand->execute(game);
    ASSERT_FALSE(game->menuVisible);
}
