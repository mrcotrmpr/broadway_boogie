#include <gtest/gtest.h>
#include "factories/artist_factory.hpp"

TEST(ArtistFactoryTest, TestCreateArtist) {
    float x = 1.5;
    float y = 2.5;
    float vx = 3.5;
    float vy = 4.5;

    auto artist = ArtistFactory::createArtist(x, y, vx, vy);

    EXPECT_EQ(artist->x, x);
    EXPECT_EQ(artist->y, y);
    EXPECT_EQ(artist->vx, vx);
    EXPECT_EQ(artist->vy, vy);
}
