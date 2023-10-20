#include <gtest/gtest.h>
#include "domain/edge.hpp"

TEST(EdgeTest, TestInitialization) {
    int x = 5;
    int y = 10;
    auto edge = std::make_shared<Edge>(x, y);
    EXPECT_EQ(edge->x, x);
    EXPECT_EQ(edge->y, y);
}
