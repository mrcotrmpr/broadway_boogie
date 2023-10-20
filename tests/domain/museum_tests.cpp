#include <gtest/gtest.h>
#include "domain/museum.hpp"
#include "domain/node.hpp"
#include "domain/node_type.hpp"

TEST(MuseumTest, TestInitialization) {
    std::vector<std::shared_ptr<NodeType>> nodeTypes;
    std::vector<std::shared_ptr<Node>> nodes;
    int numRows = 5;
    int numCols = 7;
    auto museum = std::make_shared<Museum>(numRows, numCols, nodeTypes, nodes);
    EXPECT_EQ(museum->numRows, numRows);
    EXPECT_EQ(museum->numCols, numCols);
    EXPECT_TRUE(museum->nodeTypes.empty());
    EXPECT_TRUE(museum->nodes.empty());
}
