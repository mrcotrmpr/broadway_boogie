#include <gtest/gtest.h>
#include "domain/node.hpp"
#include "domain/states/node_state.hpp"

TEST(NodeTest, TestInitialization) {
    char tag = 'A';
    int x = 5;
    int y = 10;

    auto node = std::make_shared<Node>(tag, x, y);

    EXPECT_EQ(node->tag, tag);
    EXPECT_EQ(node->x, x);
    EXPECT_EQ(node->y, y);
    EXPECT_EQ(node->interactions, 0);
    EXPECT_TRUE(node->edges.empty());
    EXPECT_TRUE(node->state == nullptr);
}
