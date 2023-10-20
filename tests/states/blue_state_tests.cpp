#include <gtest/gtest.h>
#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "domain/states/blue_state.hpp"
#include "domain/states/yellow_state.hpp"
#include "presentation/game.hpp"
#include <vector>

TEST(BlueStateTest, TestHandleInteractionWithArtist) {
    auto game = std::make_shared<Game>();
    auto node = std::make_shared<Node>('B', 0, 0);
    auto otherNode = std::make_shared<Node>('N', 0, 1);
    auto museum = std::make_shared<Museum>();
    auto artist = std::make_shared<Artist>();

    artist->direction = 1;
    node->state = std::make_shared<BlueState>();

    game->museum = museum;
    game->museum->nodes.push_back(node);
    game->museum->nodes.push_back(otherNode);

    node->state->handleInteraction(game, node, artist);
    ASSERT_EQ(node->tag, 'Y');
    ASSERT_EQ(otherNode->tag, 'B');
}

TEST(BlueStateTest, TestHandleInteractionWithoutArtist) {
    auto game = std::make_shared<Game>();
    auto node = std::make_shared<Node>('B', 0, 0);
    auto otherNode = std::make_shared<Node>('N', 0, 1);
    auto museum = std::make_shared<Museum>();

    node->state = std::make_shared<BlueState>();

    game->museum = museum;
    game->museum->nodes.push_back(node);
    game->museum->nodes.push_back(otherNode);

    node->state->handleInteraction(game, node, nullptr);
    ASSERT_EQ(node->tag, 'Y');
    ASSERT_EQ(otherNode->tag, 'B');
}
