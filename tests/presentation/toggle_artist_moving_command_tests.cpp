#include <gtest/gtest.h>
#include "presentation/commands/toggle_artist_moving_command.hpp"
#include "presentation/game.hpp"

TEST(ToggleArtistsMovingCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto toggleArtistsMovingCommand = std::make_shared<ToggleArtistsMovingCommand>();

    game->artistsMoving = false;
    game->atPresent = false;
    toggleArtistsMovingCommand->execute(game);
    ASSERT_FALSE(game->artistsMoving);

    auto museum = std::make_shared<Museum>();
    game->museum = museum;
    toggleArtistsMovingCommand->execute(game);
    ASSERT_FALSE(game->artistsMoving);

    game->atPresent = true;
    toggleArtistsMovingCommand->execute(game);
    ASSERT_TRUE(game->artistsMoving);

    toggleArtistsMovingCommand->execute(game);
    ASSERT_FALSE(game->artistsMoving);
}
