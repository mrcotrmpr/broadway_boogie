#include <gtest/gtest.h>
#include "presentation/commands/set_pathfinding_end_command.hpp"
#include "presentation/game.hpp"
#include "domain/node.hpp"
#include "domain/states/gray_state.hpp"

TEST(SetPathFindingEndCommandTest, TestExecute) {
	auto game = std::make_shared<Game>();
	auto museum = std::make_shared<Museum>();
	game->museum = museum;
	auto setPathfindingEndCommand = std::make_shared<SetPathFindingEndCommand>();

	int x = 0;
	int y = 0;
	auto testNode = std::make_shared<Node>('G', x, y);
	testNode->state = std::make_shared<GrayState>();
	game->museum->nodes.push_back(testNode);

	setPathfindingEndCommand->execute(game);

	ASSERT_TRUE(game->pathFindingEnd != nullptr);
	ASSERT_EQ(game->pathFindingEnd->x, x);
	ASSERT_EQ(game->pathFindingEnd->y, y);
}
