#include <gtest/gtest.h>
#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/gray_state.hpp"
#include "domain/states/red_state.hpp"
#include "presentation/game.hpp"

TEST(GrayStateTest, TestHandleInteraction) {
    auto game = std::make_shared<Game>();
    auto node = std::make_shared<Node>('G', 0, 0);
    auto artist = std::make_shared<Artist>();

    node->state = std::make_shared<GrayState>();

    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->interactions, 1);
    EXPECT_EQ(node->tag, 'G');

    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->interactions, 2);
    EXPECT_EQ(node->tag, 'G');

    node->state->handleInteraction(game, node, artist);
    EXPECT_EQ(node->tag, 'R');
}
