#include <gtest/gtest.h>
#include "presentation/commands/toggle_render_artists_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleRenderArtistsCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleRenderArtistsCommand = std::make_shared<ToggleRenderArtistsCommand>();

    game->renderArtists = false;

    toggleRenderArtistsCommand->execute(game);
    ASSERT_TRUE(game->renderArtists);

    toggleRenderArtistsCommand->execute(game);
    ASSERT_FALSE(game->renderArtists);
}
