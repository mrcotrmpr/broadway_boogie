#include <gtest/gtest.h>
#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/yellow_state.hpp"
#include "domain/states/gray_state.hpp"
#include "presentation/game.hpp"
#include "factories/artist_factory.hpp"

TEST(YellowStateTest, TestHandleInteraction) {
    auto game = std::make_shared<Game>();
    auto node = std::make_shared<Node>('Y', 0, 0);
    auto artist = std::make_shared<Artist>();

    node->state = std::make_shared<YellowState>();

    ASSERT_TRUE(game->newArtists.empty());

    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->interactions, 1);
    ASSERT_FALSE(game->newArtists.empty());

    node->state->handleInteraction(game, node, artist);
    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->tag, 'G');
}
