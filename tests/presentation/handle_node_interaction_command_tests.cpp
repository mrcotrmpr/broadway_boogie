#include <gtest/gtest.h>
#include "presentation/commands/handle_node_interaction_command.hpp"
#include "presentation/game.hpp"
#include "domain/node.hpp"
#include "domain/museum.hpp"
#include "domain/states/gray_state.hpp"

TEST(HandleNodeInteractionCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto museum = std::make_shared<Museum>();
    game->museum = museum;
    auto handleNodeInteractionCommand = std::make_shared<HandleNodeInteractionCommand>();

    int x = 0;
    int y = 0;
    auto testNode = std::make_shared<Node>('G', x, y);
    testNode->state = std::make_shared<GrayState>();
    game->museum->nodes.push_back(testNode);

    handleNodeInteractionCommand->execute(game);

    ASSERT_EQ(testNode->interactions, 1);
}
