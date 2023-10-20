#include <gtest/gtest.h>
#include "parsers/csv_parser.hpp"

TEST(CSVParserTest, TestParse) {
    auto csvParser = std::make_shared<CSVParser>();
    const std::string csv_data = "x,y,vx,vy\n26.25,26.24,0,1\n0,0.5,1,2\n";
    std::vector<std::shared_ptr<Artist>> loadedArtists = csvParser->parse(csv_data);

     ASSERT_FALSE(loadedArtists.empty());
     EXPECT_EQ(loadedArtists.size(), 2);

     EXPECT_EQ(loadedArtists[0]->x, 26.25f);
     EXPECT_EQ(loadedArtists[0]->y, 26.24f);
     EXPECT_EQ(loadedArtists[0]->vx, 0);
     EXPECT_EQ(loadedArtists[0]->vy, 1);
     EXPECT_EQ(loadedArtists[1]->x, 0.0f);
     EXPECT_EQ(loadedArtists[1]->y, 0.5f);
     EXPECT_EQ(loadedArtists[1]->vx, 1);
     EXPECT_EQ(loadedArtists[1]->vy, 2);
}
