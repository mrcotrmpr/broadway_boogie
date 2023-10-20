#include <gtest/gtest.h>
#include "presentation/commands/set_pathfinding_start_command.hpp"
#include "presentation/game.hpp"
#include "domain/node.hpp"
#include "domain/states/gray_state.hpp"

TEST(SetPathFindingStartCommandTest, TestExecute) {
	auto game = std::make_shared<Game>();
	auto museum = std::make_shared<Museum>();
	game->museum = museum;
	auto setPathfindingStartCommand = std::make_shared<SetPathFindingStartCommand>();

	int x = 0;
	int y = 0;
	auto testNode = std::make_shared<Node>('G', x, y);
	testNode->state = std::make_shared<GrayState>();
	game->museum->nodes.push_back(testNode);

	setPathfindingStartCommand->execute(game);

	ASSERT_TRUE(game->pathFindingStart != nullptr);
	ASSERT_EQ(game->pathFindingStart->x, x);
	ASSERT_EQ(game->pathFindingStart->y, y);
}
