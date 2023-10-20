#include <gtest/gtest.h>
#include "domain/artist.hpp"
#include "domain/node.hpp"

TEST(ArtistTest, TestInitialization) {
    auto artist = std::make_shared<Artist>(1, 2, 3, 4);
    EXPECT_EQ(artist->x, 1);
    EXPECT_EQ(artist->y, 2);
    EXPECT_EQ(artist->vx, 3);
    EXPECT_EQ(artist->vy, 4);
    EXPECT_GE(artist->direction, 0);
    EXPECT_LE(artist->direction, 3);
    EXPECT_EQ(artist->colorTag, 'B');
    EXPECT_EQ(artist->lastNode, nullptr);
    EXPECT_FALSE(artist->leftFirstNode);
}

TEST(ArtistTest, TestLastNode) {
    auto artist = std::make_shared<Artist>(1, 2, 3, 4);
    auto node = std::make_shared<Node>();
    artist->lastNode = node;
    EXPECT_EQ(artist->lastNode, node);
}

TEST(ArtistTest, TestLeftFirstNode) {
    auto artist = std::make_shared<Artist>(1, 2, 3, 4);
    artist->leftFirstNode = true;
    EXPECT_TRUE(artist->leftFirstNode);
}
