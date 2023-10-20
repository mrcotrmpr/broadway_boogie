#include <gtest/gtest.h>
#include "domain/node_type.hpp"

TEST(NodeTypeTest, TestInitialization) {
    char tag = 'A';
    int red = 255;
    int green = 128;
    int blue = 64;
    int weight = 3;

    auto nodeType = std::make_shared<NodeType>(tag, red, green, blue, weight);

    EXPECT_EQ(nodeType->tag, tag);
    EXPECT_EQ(nodeType->red, red);
    EXPECT_EQ(nodeType->green, green);
    EXPECT_EQ(nodeType->blue, blue);
    EXPECT_EQ(nodeType->weight, weight);
}
