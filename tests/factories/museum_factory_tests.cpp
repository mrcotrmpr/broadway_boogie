#include <gtest/gtest.h>
#include "factories/museum_factory.hpp"

TEST(MuseumFactoryTest, TestCreateMuseum) {
    int numRows = 5;
    int numCols = 7;
    std::vector<std::shared_ptr<NodeType>> nodeTypes;
    std::vector<std::shared_ptr<Node>> nodes;

    auto museum = MuseumFactory::createMuseum(numRows, numCols, nodeTypes, nodes);

    EXPECT_EQ(museum->numRows, numRows);
    EXPECT_EQ(museum->numCols, numCols);
    EXPECT_EQ(museum->nodeTypes, nodeTypes);
    EXPECT_EQ(museum->nodes, nodes);
}
