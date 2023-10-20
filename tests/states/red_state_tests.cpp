#include <gtest/gtest.h>
#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/red_state.hpp"
#include "domain/states/blue_state.hpp"
#include "presentation/game.hpp"

TEST(RedStateTest, TestHandleInteraction) {
    auto game = std::make_shared<Game>();
    auto node = std::make_shared<Node>('R', 0, 0);
    auto artist = std::make_shared<Artist>();

    node->state = std::make_shared<RedState>();

    game->addArtist(artist);
    ASSERT_FALSE(game->getArtists().empty());

    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->tag, 'B');
}
