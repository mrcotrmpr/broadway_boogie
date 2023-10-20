#include <gtest/gtest.h>
#include "readers/csv_reader.hpp"

TEST(CSVReaderTest, TestRead) {
    auto csvReader = std::make_shared<CSVReader>();
    const std::string csv_filename = "C:\\Users\\marco\\source\\repos\\test\\tests\\data\\artists.csv";
    std::string csv_data = csvReader->read(csv_filename);

    ASSERT_FALSE(csv_data.empty());
    ASSERT_EQ(csv_data, "x,y,vx,vy\n26.25,26.25,0,0\n26.5,26.5,0,0\n");
}
